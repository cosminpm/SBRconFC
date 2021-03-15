#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "bcClass.h"
using namespace std;

string obtenerParteDerecha(string line);
double obtenerFactorRegla(string line);
vector<string> obtenerParteIzquierda(string line);
char obtenerTipo(string line);

// Constructor
/*
    La regla va a recibir solo la parte a partir de los "dos puntos"
    puesto que la parte izquierda sera el identificador y sera la llave
    del mapa de la clase bcClass
*/

reglaClass::reglaClass(string line){
    factorCerteza = obtenerFactorRegla(line);
    parteDerecha = obtenerParteDerecha(line);
    parteIzquierda = obtenerParteIzquierda(line);
    tipo = obtenerTipo(line);
}

void reglaClass::salidaRegla(ofstream& of){
    of << "Regla: (";
    for(auto i: parteIzquierda){
        of << i << " ";
    }
    of << "con tipo: " << tipo << ")-->" << parteDerecha << "\n";
}

// Funciones get

char reglaClass::getTipo(){
    return tipo;
}

double reglaClass:: getFactorCertezaRegla(){
    return factorCerteza;
}

vector<string> reglaClass::getParteIzquierda(){
    return parteIzquierda;
}

string reglaClass::getParteDerecha(){
    return parteDerecha;
}


// Funciones show
void reglaClass:: showReglaCompleta(){
    cout << "FC: " << factorCerteza << "\n";
    cout << "Tipo: " << tipo << "\n";
    cout << "Parte I.:";
    showParteIzquierda();
    cout << "Parte D.:" << parteDerecha << "\n";

}


void reglaClass::showFactorRegla(){
    cout << "Factor certeza regla: " << factorCerteza << "\n";
}

void reglaClass::showParteDerecha(){
    cout << "Parte derecha de la regla: " << parteDerecha << "\n";
}

void reglaClass::showTipo(){
    cout << "Tipo de regla (Y, O, N): " << tipo << "\n";
}

void reglaClass::showParteIzquierda(){
    for(auto i: parteIzquierda){
        cout << i << " ";
    }
    cout << "\n";
}


// Funciones auxiliares
/**
 * @brief Funcion que obtiene el tipo de la regla
 * @param line, la cadena que se le pasa como parametro
 */
char obtenerTipo(string line){
    // Si no aparece ninguna conjuncion ni ninguna disyuncion es:
    char tipo = 'N';

    // Si aparece una conjuncion
    if ((line.find(" y ") != string::npos)){
        tipo = 'Y';
    }
    // Si aparece una disyuncion
    else if (line.find(" o ") != string::npos){
        tipo = 'O';
    }
    return tipo;
}

//vector
/**
 * @brief Funcion que obtiene la parte izquierda de la regla, es decir el antecedente
 * @param line, la cadena que se le pasa como parametro
 */

vector<string> obtenerParteIzquierda(string line){
    string palabraInicio = "Si";
    string palabraFin = "Entonces";
    vector<string> parteIzquierda;
    int eliminarInicio = line.find(palabraInicio);

    string aux = line.substr(eliminarInicio + palabraInicio.length());
    int eliminarFinal = aux.find(palabraFin);
    string aux2 = aux.substr(0, eliminarFinal);
    // Aqui ya tenemos todo lo que es la linea entre Si y Entonces

    string palabra = "";
    for (auto i: aux2){
        if(i == ' '){
            if((palabra == "o") || palabra == "y"){
                 palabra = "";
            }
            else{
                if (palabra.length() >=1) parteIzquierda.push_back(palabra);
                palabra = "";
            }

        }
        else{
            palabra = palabra + i;
        }
    }
    return parteIzquierda;
}
/**
 * @brief Funcion que obtiene la parte derecha de la regla, es decir el consecuento
 * @param line, la cadena que se le pasa como parametro
 */
string obtenerParteDerecha(string line){
    string palabra = "Entonces ";
    int final = line.find(palabra);
    string aux = line.substr(final + palabra.length());
    size_t numero = aux.find(',');
    string r = aux.substr(0, numero);
    return r;
}
/**
 * @brief Funcion que obtiene el factor de certeza de la regla
 * @param line, la cadena que se le pasa como parametro
 */
double obtenerFactorRegla(string line){
    int final = line.find("FC=");
    string aux = line.substr(final+3);
    double r = stod(aux);
    return r;
}




