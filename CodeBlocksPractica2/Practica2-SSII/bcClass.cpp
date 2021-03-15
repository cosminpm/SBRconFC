#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "bcClass.h"

using namespace std;

string obtenerIdenRegla(string line);
string cortarLinea(string line);

// Constructor
bcClass::bcClass(ifstream& fileBC){
    string line;
    getline(fileBC, line);
    numeroReglas = stoi(line);
    int auxNumero = numeroReglas;
    line.clear();
    string iden;
    string aux;
    while(auxNumero > 0){
        getline(fileBC, line);
        iden = obtenerIdenRegla(line);
        aux = cortarLinea(line);
        reglaClass regla(line);
        mapaReglas.insert(pair<string, reglaClass>(iden, regla));
        auxNumero--;
    }
}

map<string, reglaClass> bcClass::getMapaReglas(){
    return mapaReglas;
}

// Funciones show
void bcClass::showNumeroReglas(){
    cout << "Numero Reglas: " << numeroReglas << "\n";
}

void bcClass::showMapaReglas(){
    cout << "Mapa Reglas:\n";
    for (auto i: mapaReglas){
        cout << i.first << "\n";
        i.second.showReglaCompleta();

    }
}
/**
 * @brief Funcion que corta una linea en los dos puntos
 * @param line, la cadena que se le pasa como parametro
 */

string cortarLinea(string line){
    int fin = line.find(':');
    string r = line.substr(fin, line.length() - fin);
    return r;
}
/**
 * @brief Funcion que obtiene el identificador de la regla
 * @param line, la cadena que se le pasa como parametro
 */
string obtenerIdenRegla(string line){
    int fin = line.find(':');
    string r = line.substr(0, fin);
    return r;
}
