#include <fstream>
#include <iostream>
#include <string.h>
#include <string_view>
#include "bhClass.h"
#include "bcClass.h"
#include "AlgoritmoSBR.h"
using namespace std;


void checkError(int argc, const char *argv[]);
int endsWith(const char * str, const char* suffix);

int main(int argc, char const *argv[])
{
    // Se abren BC y BH
    checkError(argc, argv);

    ifstream fileBC(argv[1]);
    ifstream fileBH(argv[2]);

    string aux1 = string(argv[1]);
    aux1 = aux1.substr(0, aux1.find('.'));
    string aux2 = string(argv[2]);
    aux2 = aux2.substr(0, aux2.find('.'));

    ofstream MyFile(aux1 + aux2 + ".txt");

    bhClass bh(fileBH);
    bcClass bc(fileBC);

    MyFile << "Fichero de salida.\n";
    MyFile << "Nombre de la BC: " << aux1 << "\n";
    MyFile << "Nombre de la BH: " << aux2 << "\n";
    MyFile << "Objetivo: " << bh.getObjetivo() << "\n";

    double exito = verificar(bc, bh, bh.getObjetivo(), MyFile);
    MyFile << "\nFC Meta:" << exito << "\n";
    cout <<"Objetivo: "<< bh.getObjetivo() << "\nFC: "<< exito << "\n";

    // Se cierran BC y BH
    fileBC.close();
    fileBH.close();
    return 0;
}

// Funciones auxiliares
/**
 * @brief Funcion checkError comprueba si se han producido errores al pasar argumentos al programa
 * Se pasan los mismos argumentos que al main
 * @param argc
 * @param argv
 */
void checkError(int argc, const char *argv[]){
    const char* terminacionFichero = ".txt";

    if (argc != 3){
        cerr << "Uso del ejecutable:./ejecutable.exe BCfile.txt BHfile.txt\n";
        exit(-1);
    }

    int finBC = endsWith(argv[1], terminacionFichero);
    int finBH = endsWith(argv[2], terminacionFichero);

    if (finBC == false || finBH == false){
        cout << argv[1] << "\n" << argv[2];
        cerr << "Error: Ambos ficheros tienen que ser de tipo .txt\n";
        exit(-1);
        }
}

/**
 * @brief Funcion que comprueba si una cadena termina con un sufijo determinado
 * @param str la cadena que se comprueba
 * @param suffix el sufijo
 * @return 0 o 1 siendo verdadero o falso
 */

int endsWith(const char * str,const char* suffix) {

  if( str == NULL || suffix == NULL )
    return 0;

  size_t str_len = strlen(str);
  size_t suffix_len = strlen(suffix);

  if(suffix_len > str_len)
    return 0;

  return 0 == strncmp( str + str_len - suffix_len, suffix, suffix_len);
}
