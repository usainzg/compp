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

string Codigo::iniNom() {
    return "";
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
