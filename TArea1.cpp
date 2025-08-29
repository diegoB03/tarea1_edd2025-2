#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Dato {
    unsigned int Id;            //id unico por estudiante
    char Nombre[50];            //Nombre y apellido
    char Fecha_nacimiento[11];  //SE DESCRIBE SOLO
    int Notas[3];               //Notas por alumno
    char Curso[7];              //sigla del curso
    unsigned short VTR;         //veces que se ha rendido el ramo

};



//Funcion 1. Funcion que permita leer el archivo datos.dat y cargarlo en memoria dinamica.

Dato* Leer_archivo(const string &nombre_archivo){
    unsigned int N; 
    ifstream ar;
    //int i;
    Dato *datosBrutos;
    ar.open("datos.dat", ios::binary);
    if (!ar.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        break;
    }

    ar.read((char*)&N, sizeof(unsigned int));
    datosBrutos = new Dato[N];
    ar.read((char*)datosBrutos, sizeof(Dato)*N);
    ar.close();

    return datosBrutos;
}


int main(){
    Leer_archivo("datos.dat");
    cout << datosBrutos[0].Nombre << endl;
    return 0;
}