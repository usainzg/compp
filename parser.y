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
   void yyerror (const char *msg) {
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
}

/* declaración de tokens. Esto debe coincidir con tokens.l */
%token <str> TIDENTIFIER TINTEGER TDOUBLE
%token <str> TMUL TDIV TPLUS TMINUS
%token <str> TCGLE TCLT TCLE TCGT TCGE  TEQUAL TNEQUAL
%token <str> TSEMIC TASSIG TLBRACE TRBRACE TLPAREN TRPAREN TCOMMA
%token <str> RPROGRAM RPROCEDURE
%token <str> RFLOAT RINTEGER
%token <str> RWHILE RUNTIL RIF RELSE RFOREVER RDO RSKIP REXIT
%token <str> RREAD RPRINTLN


// %nonassoc TEQUAL TNEQUAL TCLE TCGT TCGE 
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


%start programa

%%

programa : RPROGRAM TIDENTIFIER 
    { codigo.anadirInstruccion(*$1 + " " + *$2 + ";"); } 
    declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE 
    { codigo.anadirInstruccion("halt;"); codigo.escribir(); }
    ;

declaraciones : tipo lista_de_ident 
    { codigo.anadirDeclaraciones($2->lnom, $1->clase); delete $1; delete $2; } 
    TSEMIC declaraciones
    | /* vacio */
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
    | /* vacio */ { $$ = new resto_lista_idstruct; $$->lnom = codigo.iniLista(""); }
    ;

tipo : RINTEGER { $$ = new tipostruct; $$->clase = "ent"; }
    | RFLOAT { $$ = new tipostruct; $$->clase = "real"; }
    ;

decl_de_subprogs : decl_de_subprograma decl_de_subprogs
    | /* vacio */
    ;

decl_de_subprograma : RPROCEDURE TIDENTIFIER  { codigo.anadirInstruccion(*$1 + " " + *$2 + ";"); } argumentos declaraciones
    decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE { codigo.anadirInstruccion("endproc;"); }
    ;

argumentos : TLPAREN lista_de_param TRPAREN
    | /* vacio */
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
    | /* vacio */
    ;

lista_de_sentencias : sentencia lista_de_sentencias
    { 
        $$ = new lista_de_sentenciasstruct; 
        $$->exits = *codigo.unir($1->exits, $2->exits); 
        $$->skips = *codigo.unir($1->skips, $2->skips);
        delete $1; delete $2;
    }
    | /*vacio*/ 
    { 
        $$ = new lista_de_sentenciasstruct; $$->exits = codigo.iniLista(0); $$->skips = codigo.iniLista(0); 
    }
    ;

sentencia : variable TASSIG expr TSEMIC
    {
        codigo.anadirInstruccion($1->nom + " := " + $3->nom + ";");
		$$ = new sentenciastruct;
		$$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
		delete $1; delete $3;
    }
    | RIF expr TLBRACE M lista_de_sentencias TRBRACE M TSEMIC 
    {
        codigo.completarInstrucciones($2->trues, $4->ref);
		codigo.completarInstrucciones($2->falses, $7->ref);
		$$ = new sentenciastruct; 
        $$->exits = $5->exits;
        $$->skips = $5->skips;
		delete $2; delete $4; delete $5; delete $7;
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
    | RDO TLBRACE M lista_de_sentencias TRBRACE RUNTIL M expr RELSE TLBRACE M lista_de_sentencias TRBRACE M TSEMIC
    {
        codigo.completarInstrucciones($8->trues, $11->ref);
        codigo.completarInstrucciones($8->falses, $3->ref);
		codigo.completarInstrucciones($4->skips, $7->ref);
        codigo.completarInstrucciones($4->exits, $14->ref);
        codigo.completarInstrucciones($12->exits, $14->ref);
		$$ = new sentenciastruct;
		$$->exits = codigo.iniLista(0);
        $$->skips = codigo.iniLista(0);
		delete $3; delete $4; delete $7; delete $8; delete $11; delete $12; delete $14;
    }
    | RSKIP RIF expr M TSEMIC
    {
        codigo.completarInstrucciones($3->falses, $4->ref);
        $$ = new sentenciastruct;
		$$->exits = codigo.iniLista(0);
        $$->skips = $3->trues;
        delete $3; delete $4;
    }
    | REXIT M TSEMIC
    {
        $$ = new sentenciastruct;
		$$->exits = codigo.iniLista(codigo.obtenRef());
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
    ;

M: { $$ = new mstruct; $$->ref = codigo.obtenRef(); };

variable : TIDENTIFIER { $$ = new variablestruct; $$->nom = *$1; }
    ;

expr : 
    expr TEQUAL expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " = " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCGT expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " > " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCLT expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " < " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCGE expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " >= " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TCLE expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " <= " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TNEQUAL expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.iniNom();
        $$->trues = codigo.iniLista(codigo.obtenRef());
        $$->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + $1->nom + " /= " + $3->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete $1; delete $3;
    }
    | expr TPLUS expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.nuevoId();
        codigo.anadirInstruccion($$->nom + " := " + $1->nom + " + " + $3->nom + ";");
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
        delete $1; delete $3;
    }
    | expr TMINUS expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.nuevoId();
        codigo.anadirInstruccion($$->nom + " := " + $1->nom + " - " + $3->nom + ";");
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
        delete $1; delete $3;
    }
    | expr TMUL expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.nuevoId();
        codigo.anadirInstruccion($$->nom + " := " + $1->nom + " * " + $3->nom + ";");
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
        delete $1; delete $3;
    }
    | expr TDIV expr
    {
        $$ = new expresionstruct;
        $$->nom = codigo.nuevoId();
        codigo.anadirInstruccion($$->nom + " := " + $1->nom + " / " + $3->nom + ";");
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
        delete $1; delete $3;
    }
    | variable
    {
        $$ = new expresionstruct;
        $$->nom = $1->nom;
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
        delete $1;
    }
    | TINTEGER
    {
        $$ = new expresionstruct;
        $$->nom = *$1;
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
    }
    | TDOUBLE
    {
        $$ = new expresionstruct;
        $$->nom = *$1;
        $$->trues = codigo.iniLista(0);
        $$->falses = codigo.iniLista(0);
    }
    | TLPAREN expr TRPAREN
    {
        $$ = $2;
    }
    ;