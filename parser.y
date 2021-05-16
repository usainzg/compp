%define parse.error verbose

%{
    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std; 
    
    extern int yylex();
    extern int yylineno;
    extern char *yytext;
    
    extern bool hayError;
    void yyerror (const char *msg) {
        hayError = true;
        printf("line %d: %s\n", yylineno, msg) ;
    }

    #include "Codigo.hpp"
    
    Codigo codigo;
%}

/* 
qué atributos tienen los tokens 
*/
%union {
    std::string *str;
    lista_de_identstruct *lident;
    resto_lista_idstruct *rlident;
    tipostruct *tp;
    clase_parstruct *cp;
    lista_de_sentenciasstruct *lsent;
    sentenciastruct *sent;
    mstruct *m;
    variablestruct *var;
    expresionstruct *expr; 
    argumentostruct *arg;
}

/* declaración de tokens. Esto debe coincidir con tokens.l */
%token <str> TIDENTIFIER TINTEGER TDOUBLE
%token <str> TMUL TDIV TPLUS TMINUS
%token <str> TCGLE TCLT TCLE TCGT TCGE  TEQUAL TNEQUAL
%token <str> TSEMIC TASSIG TLBRACE TRBRACE TLPAREN TRPAREN TCOMMA
%token <str> RPROGRAM RPROCEDURE
%token <str> RFLOAT RINTEGER
%token <str> RFOR RWHILE RUNTIL RIF RELSE RFOREVER RDO RSKIP REXIT
%token <str> RAND ROR RNOT
%token <str> RREAD RPRINTLN


%right RAND ROR
%left RNOT
%left TEQUAL TCGT TCLT TCGE TCLE TNEQUAL
%left TPLUS TMINUS
%left TMUL TDIV

/* declaración de no terminales. */
%type <lident> lista_de_ident
%type <rlident> resto_lista_id
%type <tp> tipo
%type <cp> clase_par
%type <lsent> lista_de_sentencias
%type <sent> sentencia
%type <var> variable
%type <expr> expr
%type <m> M
%type <arg> lista_de_argumentos
%type <arg> resto_lista_argumentos


%start programa

%%

programa : RPROGRAM TIDENTIFIER 
    { codigo.anadirInstruccion(*$1 + " " + *$2 + ";"); } 
    declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE 
    { 
        codigo.anadirInstruccion("halt;"); 
        if (!hayError) codigo.escribir(); 
        codigo.desempilar(); 
    }
    ;

declaraciones : tipo lista_de_ident 
    { codigo.anadirDeclaraciones($2->lnom, $1->clase); delete $1; delete $2; } 
    TSEMIC declaraciones
    | %empty /* vacio */
    ;

lista_de_ident : TIDENTIFIER resto_lista_id
    { 
        $$ = new lista_de_identstruct; 
        $$->lnom = codigo.iniLista(*$1);
        $$->lnom = *codigo.unir($$->lnom, $2->lnom);
        delete $2;
    }
    ;

resto_lista_id : TCOMMA TIDENTIFIER resto_lista_id
    {
        $$ = new resto_lista_idstruct;
        $$->lnom = codigo.iniLista(*$2);
        $$->lnom = *codigo.unir($$->lnom, $3->lnom);
        delete $3;
    }
    | %empty /* vacio */ { $$ = new resto_lista_idstruct; $$->lnom = codigo.iniLista(""); }
    ;

tipo : RINTEGER { $$ = new tipostruct; $$->clase = Codigo::NUMERO_INT; }
    | RFLOAT { $$ = new tipostruct; $$->clase = Codigo::NUMERO_FLOAT; }
    ;

decl_de_subprogs : decl_de_subprograma decl_de_subprogs
    | %empty /* vacio */
    ;

decl_de_subprograma : RPROCEDURE TIDENTIFIER  { codigo.declararProcedimiento(*$2); } argumentos declaraciones
    decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE { codigo.finProcedimiento(); }
    ;

argumentos : TLPAREN lista_de_param TRPAREN
    | %empty /* vacio */
    ;

lista_de_param : tipo clase_par lista_de_ident 
    { codigo.anadirParametros($3->lnom, $2->tipo, $1->clase); delete $1; delete $2; delete $3; } 
    resto_lis_de_param
    ;

clase_par : 
    TCGE { $$ = new clase_parstruct; $$->tipo = "ref"; } // out
    | TCLE { $$ = new clase_parstruct; $$->tipo = "val"; } // int
    | TCGLE { $$ = new clase_parstruct; $$->tipo = "ref"; } // in out
    ;

resto_lis_de_param : TSEMIC tipo clase_par lista_de_ident 
    { codigo.anadirParametros($4->lnom, $3->tipo, $2->clase); delete $2; delete $3; delete $4; } 
    resto_lis_de_param
    | %empty /* vacio */
    ;

lista_de_sentencias : sentencia lista_de_sentencias
    { 
        $$ = new lista_de_sentenciasstruct; 
        $$->exits = *codigo.unir($1->exits, $2->exits); 
        $$->skips = *codigo.unir($1->skips, $2->skips);
        delete $1; delete $2;
    }
    | %empty /*vacio*/ 
    { 
        $$ = new lista_de_sentenciasstruct; 
        $$->exits = codigo.iniLista(0); 
        $$->skips = codigo.iniLista(0); 
    }
    ;

sentencia : variable TASSIG expr TSEMIC
    {
        try {
            string tmp;
            string tipoVar = codigo.obtenerTipo($1->nom);

            if (codigo.esTipo(tipoVar, Codigo::NUMERO_INT) && codigo.esTipo($3->tipo, Codigo::NUMERO_FLOAT)){
                tmp = codigo.nuevoId();
                codigo.anadirInstruccion(tmp + " := real2ent " + $3->nom + ";");
            } else if (codigo.esTipo(tipoVar, Codigo::NUMERO_FLOAT) && codigo.esTipo($3->tipo, Codigo::NUMERO_INT)) {
                tmp = codigo.nuevoId();
                codigo.anadirInstruccion(tmp + " := ent2real " + $3->nom + ";");
            } else if (! codigo.esTipo(tipoVar, $3->tipo)){
                yyerror(string("Error semántico. No se puede asignara una variable de tipo " + $3->tipo + " a otra de tipo " + tipoVar + ".").c_str());
            } else {
                tmp = $3->nom;
            }

            codigo.anadirInstruccion($1->nom + " := " + tmp + ";");
        } catch (string s) {}
        $$ = new sentenciastruct;
        $$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
        delete $1; delete $3;
    }
    | RIF expr TLBRACE M lista_de_sentencias TRBRACE M TSEMIC 
    {	
        try {
            codigo.comprobarTipos($2->tipo, Codigo::BOOLEANO);
            codigo.completarInstrucciones($2->trues, $4->ref);
            codigo.completarInstrucciones($2->falses, $7->ref);
            $$ = new sentenciastruct; 
            $$->exits = $5->exits;
            $$->skips = $5->skips;
            delete $2; delete $4; delete $5; delete $7;
        } catch (string s) {
            yyerror("Error semántico. La condición de la estructura IF debe ser de tipo Codigo::BOOLEANO.");
        }
    }
    | RWHILE RFOREVER TLBRACE M lista_de_sentencias TRBRACE M TSEMIC
    {
        codigo.anadirInstruccion("goto" + to_string($4->ref) + ";");
        codigo.completarInstrucciones($5->exits, $7->ref + 1);
        $$ = new sentenciastruct;
        $$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
        delete $4; delete $5; delete $7;
    }
    | RDO TLBRACE M lista_de_sentencias TRBRACE RUNTIL M expr 
    {
        try {
            codigo.comprobarTipos($8->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror("Error semantico. Condicion debe ser booleano.");
        }
    }
    RELSE TLBRACE M lista_de_sentencias TRBRACE M TSEMIC
    {
        codigo.completarInstrucciones($8->trues, $12->ref);
        codigo.completarInstrucciones($8->falses, $3->ref);
        codigo.completarInstrucciones($4->skips, $7->ref);
        codigo.completarInstrucciones($4->exits, $15->ref);
        codigo.completarInstrucciones($13->exits, $15->ref);
        $$ = new sentenciastruct;
        $$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
        delete $3; delete $4; delete $7; delete $8; delete $11; delete $12; delete $14;
    }
    | RSKIP RIF expr M TSEMIC
    {
        try {
            codigo.comprobarTipos($3->tipo, Codigo::BOOLEANO);
            codigo.completarInstrucciones($3->falses, $4->ref);
        } catch (string s) {
            yyerror("Error semántico. La condición de la estructura SKIP IF debe ser de tipo booleano.");
        }
        $$ = new sentenciastruct;
        $$->exits = codigo.iniLista(0);
        $$->skips = $3->trues;
        delete $3; delete $4;
    }
    | REXIT M TSEMIC
    {
        $$ = new sentenciastruct;
        $$->exits = codigo.iniLista($2->ref);
        $$->skips = codigo.iniLista(0);
        codigo.anadirInstruccion("goto");
    }
    | RREAD TLPAREN variable TRPAREN TSEMIC
    {
        codigo.anadirInstruccion("read " + $3->nom + ";");
        $$ = new sentenciastruct; 
        $$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
        delete $3;
    }
    | RPRINTLN TLPAREN expr TRPAREN TSEMIC
    {
        codigo.anadirInstruccion("write " + $3->nom + ";");
        codigo.anadirInstruccion("writeln;");
        $$ = new sentenciastruct; 
        $$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
        delete $3;
    }
    | RFOR TLPAREN tipo TIDENTIFIER TASSIG expr 
    {
        string variableAsignar;
        try {
            codigo.comprobarTipos($6->tipo, $3->clase);
            variableAsignar = $6->nom;
        } catch (string s) {
            if (codigo.esTipo($3->clase, Codigo::NUMERO_INT)) {
                variableAsignar = codigo.nuevoId();
                codigo.anadirInstruccion(variableAsignar + " := real2ent " + $6->nom + ";");
            } else if (codigo.esTipo($3->clase, Codigo::NUMERO_FLOAT)) {
                variableAsignar = codigo.nuevoId();
                codigo.anadirInstruccion(variableAsignar + " := ent2real " + $6->nom + ";");
            } else {
                yyerror(s.c_str());
            }
        }
        TablaSimbolos ts;
        codigo.empilar(ts);
        codigo.anadirDeclaraciones(codigo.iniLista(*$4), $3->clase);
        codigo.anadirInstruccion(*$4 + " := " + variableAsignar + ";");
    }
    TSEMIC M expr 
    {
        try {
            codigo.comprobarTipos($10->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror("Error semántico. La condición de parada debe ser de tipo booleano! ");
        }
    }
    M TSEMIC variable TASSIG expr TRPAREN TLBRACE lista_de_sentencias M TRBRACE TSEMIC
    {
        if (*$4 != $14->nom) {
			yyerror(string("Error semántico. Se debe actualizar la variable " + string(*$4) + " no la variable " + $14->nom + ".").c_str());
		}
		try{
			codigo.comprobarTipos($14->tipo, $16->tipo);
			codigo.anadirInstruccion($14->nom + " := " + $16->nom + ";");
			codigo.anadirInstruccion("goto " + to_string($9->ref) + ";");
			codigo.completarInstrucciones($10->trues, $12->ref);
			codigo.completarInstrucciones($10->falses, $20->ref + 2);
			codigo.completarInstrucciones($19->exits, $20->ref + 2);
		} catch (string s){
			yyerror(s.c_str());
		}
		codigo.desempilar();
		$$ = new sentenciastruct; $$->exits = codigo.iniLista(0); $$->skips = codigo.iniLista(0);
		delete $3; delete $6; delete $9; delete $10; delete $12; delete $14; delete $16; delete $19; delete $20;
    }
    | TIDENTIFIER TLPAREN lista_de_argumentos TRPAREN TSEMIC // procedimientos
    {
        try {
            codigo.llamadaProcedimiento(*$1, $3->lparam);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new sentenciastruct; 
        $$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
        delete $3;
    }
    ;

lista_de_argumentos : expr resto_lista_argumentos
    {
        $$ = new argumentostruct;
        $$->lparam = codigo.iniLista($1->nom, $1->tipo);
        $$->lparam = *codigo.unir($$->lparam, $2->lparam);
        delete $1; delete $2;
    } 
    ;

resto_lista_argumentos : TCOMMA expr resto_lista_argumentos
    {
        $$ = new argumentostruct;
        $$->lparam = codigo.iniLista($2->nom, $2->tipo);
        $$->lparam = *codigo.unir($$->lparam, $3->lparam);
        delete $2; delete $3;
    }
    | %empty {$$ = new argumentostruct; $$->lparam = codigo.iniLista("", "");}
    ;

M: %empty { $$ = new mstruct; $$->ref = codigo.obtenRef(); };

variable : TIDENTIFIER 
    { 
        string tipo;
        try {
            tipo = codigo.obtenerTipo(*$1);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new variablestruct; 
        $$->nom = *$1;
        $$->tipo = tipo;
    }
    ;

expr : 
    expr TEQUAL expr
    {
        try {
            codigo.comprobarTipos($1->tipo, $3->tipo);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " = " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCGT expr
    {
        try {
            codigo.comprobarTipos($1->tipo, Codigo::NUMERO);
            codigo.comprobarTipos($3->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " > " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCLT expr
    {
        try {
            codigo.comprobarTipos($1->tipo, Codigo::NUMERO);
            codigo.comprobarTipos($3->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " < " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCGE expr
    {
        try {
            codigo.comprobarTipos($1->tipo, Codigo::NUMERO);
            codigo.comprobarTipos($3->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " >= " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCLE expr
    {
        try {
            codigo.comprobarTipos($1->tipo, Codigo::NUMERO);
            codigo.comprobarTipos($3->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " <= " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TNEQUAL expr
    {
        try {
            codigo.comprobarTipos($1->tipo, $3->tipo);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " /= " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr RAND M expr
    {
        try {
            codigo.comprobarTipos($1->tipo, Codigo::BOOLEANO);
            codigo.comprobarTipos($4->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        codigo.completarInstrucciones($1->trues, $3->ref);
        $$->trues = $4->trues;
        $$->falses = *codigo.unir($1->falses, $4->falses);
        delete $1; delete $3;
    }
    | expr ROR M expr
    {
        try {
            codigo.comprobarTipos($1->tipo, Codigo::BOOLEANO);
            codigo.comprobarTipos($4->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        codigo.completarInstrucciones($1->falses, $3->ref);
        $$->trues = *codigo.unir($1->trues, $4->trues);
        $$->falses = $4->falses;
        delete $1; delete $3;
    }
    | RNOT expr
    {
        try {
            codigo.comprobarTipos($2->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->tipo = Codigo::BOOLEANO;
        $$->trues = $2->falses;
        $$->falses = $2->trues;
    }
    | expr TPLUS expr
    {
        $$ = new expresionstruct;
        try {
            codigo.operacionAritmetica($$, *$1, *$3, *$2); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            $$->nom = codigo.iniNom();
            $$->tipo = $1->tipo;
            $$->trues = codigo.iniLista(0);
            $$->falses = codigo.iniLista(0);
        }
        delete $1; delete $3;
    }
    | expr TMINUS expr
    {
        $$ = new expresionstruct;
        try {
            codigo.operacionAritmetica($$, *$1, *$3, "-"); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            $$->nom = codigo.iniNom();
            $$->tipo = $1->tipo;
            $$->trues = codigo.iniLista(0);
            $$->falses = codigo.iniLista(0);
        }
        delete $1; delete $3;
    }
    | expr TMUL expr
    {
        $$ = new expresionstruct;
        try {
            codigo.operacionAritmetica($$, *$1, *$3, "*"); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            $$->nom = codigo.iniNom();
            $$->tipo = $1->tipo;
            $$->trues = codigo.iniLista(0);
            $$->falses = codigo.iniLista(0);
        }
        delete $1; delete $3;
    }
    | expr TDIV expr
    {
        $$ = new expresionstruct;
        codigo.anadirInstruccion("if " + $3->nom + " = 0 goto ErrorDiv0;");
        try {    
            codigo.operacionAritmetica($$, *$1, *$3, "/"); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            $$->nom = codigo.iniNom();
            $$->tipo = $1->tipo;
            $$->trues = codigo.iniLista(0);
            $$->falses = codigo.iniLista(0);
        }
        delete $1; delete $3;
    }
    | variable
    {
        $$ = new expresionstruct;
        $$->nom = $1->nom;
        $$->tipo = $1->tipo;
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
        delete $1;
    }
    | TINTEGER
    {
        $$ = new expresionstruct;
        $$->nom = *$1;
        $$->tipo = Codigo::NUMERO_INT;
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
    }
    | TDOUBLE
    {
        $$ = new expresionstruct;
        $$->nom = *$1;
        $$->tipo = Codigo::NUMERO_FLOAT;
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
    }
    | TLPAREN expr TRPAREN
    {
        $$ = $2;
    }
    ;