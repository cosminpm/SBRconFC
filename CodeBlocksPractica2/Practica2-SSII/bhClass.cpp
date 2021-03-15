#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "bhClass.h"

double obtenerFactor(string line);
string obtenerHecho(string line);
using namespace std;


// Constructor
bhClass::bhClass(ifstream& fileBH){
    string line;
    getline(fileBH, line);
    numeroHechos = stoi(line);

    line.clear();
    bool continuar = true;
    getline(fileBH, line);

    if (line == "Objetivo"){
        continuar = false;
    }
    while(continuar){
        string hecho = obtenerHecho(line);
        double factor = obtenerFactor(line);
        mapaHechos.insert(pair<string, double>(hecho, factor));
        getline(fileBH, line);

        if (line == "Objetivo"){
            continuar = false;
        }
    }
    line.clear();
    getline(fileBH, line);
    objetivo = line;
}

void bhClass::aniadirEntradaMapa(string hecho, double factor){
    mapaHechos.insert({hecho, factor});
}

void bhClass::incrementarNumeroHechos(){
    numeroHechos+=1;
}

// Funciones get

int bhClass::getNumeroHechos(){
    return numeroHechos;
}

string bhClass::getObjetivo(){
    return objetivo;
}

map<string, double> bhClass::getMapaHechos(){
    return mapaHechos;
}

// Funciones show
void bhClass::showMap(){
    cout << "Mapa Hechos\n";
    for(auto elem: mapaHechos){
        cout << elem.first << " " << elem.second << "\n";
    }
}

void bhClass::showNumeroHechos(){
    cout << "NumeroHechos: " << numeroHechos << "\n";
}

void bhClass:: showObjetivo(){
    cout << "Objetivo: " << objetivo << "\n";
}

/**
 * @brief Funcion que obtiene el hecho
 * @param line, la cadena que se le pasa como parametro
 */
string obtenerHecho(string line){
    size_t pos = line.find(',');
    return line.substr(0, pos);
}

/**
 * @brief Funcion que obtiene el factor del hecho
 * @param line, la cadena que se le pasa como parametro
 */
double obtenerFactor(string line){
    int final = line.find("FC=");
    string aux = line.substr(final+3);

    double r = stod(aux);
    return r;
}
