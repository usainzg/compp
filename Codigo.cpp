#include "Codigo.hpp"

using namespace std;

const string Codigo::NUMERO_INT = "ent";
const string Codigo::NUMERO_FLOAT = "real";
const string Codigo::NUMERO = NUMERO_INT + NUMERO_FLOAT;
const string Codigo::BOOLEANO = "bool";

/****************/
/* Constructora */
/****************/

Codigo::Codigo()
{
    siguienteIdentificador = 1;
    TablaSimbolos ts;
    this->empilar(ts);
}

/************************/
/* siguienteInstruccion */
/************************/

int Codigo::siguienteInstruccion() const
{
    return instrucciones.size() + 1;
}

/***********/
/* nuevoId */
/***********/

string Codigo::nuevoId()
{
    stringstream cadena;
    cadena << "_t" << siguienteIdentificador++;
    return cadena.str();
}

/*********************/
/* anadirInstruccion */
/*********************/

void Codigo::anadirInstruccion(const string &instruccion)
{
    stringstream cadena;
    cadena << siguienteInstruccion() << ": " << instruccion;
    instrucciones.push_back(cadena.str());
}

/***********************/
/* anadirDeclaraciones */
/***********************/

void Codigo::anadirDeclaraciones(const vector<string> &idNombres, const string &tipoNombre)
{
    vector<string>::const_iterator iter;
    for (iter = idNombres.begin(); iter != idNombres.end(); iter++)
    {
        pilaTS.tope().anadirVariable(*iter, tipoNombre);
        anadirInstruccion(tipoNombre + " " + *iter + ";");
    }
}

/*********************/
/* anadirParametros  */
/*********************/

void Codigo::anadirParametros(const vector<string> &idNombres, const string &pTipo, const string &tipoNombre)
{
    vector<string>::const_iterator iter;
    for (iter = idNombres.begin(); iter != idNombres.end(); iter++)
    {
        pilaTS.tope().anadirParametros(this->procedimientoActual, *iter, pTipo, tipoNombre);
        anadirInstruccion(pTipo + "_" + tipoNombre + " " + *iter + ";");
    }
}

/**************************/
/* completarInstrucciones */
/**************************/

void Codigo::completarInstrucciones(vector<int> &numerosInstrucciones, const int referencia)
{
    stringstream cadena;
    vector<int>::iterator iter;
    cadena << " " << referencia;
    for (iter = numerosInstrucciones.begin(); iter != numerosInstrucciones.end(); iter++)
    {
        instrucciones[*iter - 1].append(cadena.str() + ";");
    }
}

/************/
/* escribir */
/************/

void Codigo::escribir() const
{
    //const string nombreFichero("output.txt");
    //fstream f(nombreFichero.c_str(), fstream::out);
    vector<string>::const_iterator iter;
    for (iter = instrucciones.begin(); iter != instrucciones.end(); iter++)
    {
        cout << *iter << endl;
        //f << *iter << endl;
    }
    //f.close();
}

/************/
/* obtenRef */
/************/

int Codigo::obtenRef() const
{
    return siguienteInstruccion();
}

void Codigo::empilar(const TablaSimbolos &ts) {
    pilaTS.empilar(ts);
}

void Codigo::desempilar(){
    pilaTS.desempilar();
}

void Codigo::declararProcedimiento(const string &pProc) {
    this->procedimientoActual = pProc;
    pilaTS.tope().anadirProcedimiento(pProc);
    TablaSimbolos ts;
    this->empilar(ts);
    this->anadirInstruccion("proc " + pProc + ";");
}

void Codigo::finProcedimiento() {
    this->procedimientoActual = "";
    this->desempilar();
}

void Codigo::comprobarTipos(const string &pTipo1, const string &pTipo2) {
    if (pTipo2.find(pTipo1) == string::npos){
        throw string("Error semántico. Los tipos " + pTipo1 + " y " + pTipo2 + " no concuerdan.");
    }
}

bool Codigo::esTipo(const string &pTipo, const string &pQuery){
    return pTipo.find(pQuery) != string::npos;
}

void Codigo::llamadaProcedimiento (const string &proc, const vector<string> &lnom) {
    try {
        this->pilaTS.verificarNumArgs(proc, lnom.size());
        for (int i = 0; i < lnom.size(); i++) {
            pair<string, string> param = this->pilaTS.obtenerTiposParametro(proc, i);
            this->comprobarTipos(param.second, this->pilaTS.obtenerTipo(lnom[i]));
            this->anadirInstruccion("param_" + param.first + " " + lnom[i] + ";");
        }
        this->anadirInstruccion("call " + proc + ";");
    } catch (string s) {
        throw s;
    }
}

string Codigo::iniNom() {
    return "";
}

string Codigo::obtenerTipo(const string &id){
    return pilaTS.obtenerTipo(id);
}

void Codigo::operacionAritmetica(expresionstruct *dobleDolar, const expresionstruct &op1, const expresionstruct &op2, const string &operacion) {
    string tipoFinal, tmp;
    int opCast = 0;

    if (this->esTipo(this->NUMERO_INT, op1.tipo) && this->esTipo(this->NUMERO_FLOAT, op2.tipo)) {
        tipoFinal = this->NUMERO_FLOAT;
        opCast = 1;
        tmp = this->nuevoId();
    } else if (this->esTipo(this->NUMERO_FLOAT, op1.tipo) && this->esTipo(this->NUMERO_INT, op2.tipo)) {
        tipoFinal = this->NUMERO_FLOAT;
        opCast = 2;
        tmp = this->nuevoId();
    } else if (this->esTipo(op1.tipo, op2.tipo)) {
        if (operacion.find("/") != string::npos) tipoFinal = this->NUMERO_FLOAT;
        else tipoFinal = op1.tipo;
    } else {
        throw string("Error semántico. La operación " + operacion + " no se aplica sobre variables booleanas.");
    }

    dobleDolar->nom = this->nuevoId();
    dobleDolar->trues = this->iniLista(0);
    dobleDolar->falses = this->iniLista(0);
    dobleDolar->tipo = tipoFinal;

    switch(opCast) {
        case 0:
            this->anadirInstruccion(dobleDolar->nom + " := " + op1.nom + " " + operacion + " " + op2.nom + ";");
            break;
        case 1:
            this->anadirInstruccion(tmp + " := ent2real " + op1.nom + ";");
            this->anadirInstruccion(dobleDolar->nom + " := " + tmp + " " + operacion + " " + op2.nom + ";");
            break;
        case 2:
            this->anadirInstruccion(tmp + " := ent2real " + op2.nom + ";");
            this->anadirInstruccion(dobleDolar->nom + " := " + op1.nom + " " + operacion + " " + tmp + ";");
            break;
    }
}

vector<int> Codigo::iniLista(const int &arg)
{
    vector<int> result;
    if (arg != 0)
        result.push_back(arg);
    return result;
}

vector<string> Codigo::iniLista(const string &arg)
{
    vector<string> result;
    if (arg != "")
        result.push_back(arg);
    return result;
}

bool esVacia(const vector<int> &lista) {
    return lista.empty();
}

vector<int> *Codigo::unir(const vector<int> &list1, const vector<int> &list2) 
{
    vector<int> *merged = new vector<int>(list1);
    merged->insert(merged->end(),list2.begin(),list2.end());
    return merged;
}

vector<string> *Codigo::unir(const vector<string> &list1, const vector<string> &list2) 
{
    vector<string> *merged = new vector<string>(list1);
    merged->insert(merged->end(),list2.begin(),list2.end());
    return merged;
}
