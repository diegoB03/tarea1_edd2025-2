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
    unsigned long N; 
    ifstream ar;
    //int i;
    Dato *datosBrutos;
    ar.open("datos.dat", ios::binary);
    if (!ar.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    ar.read((char*)&N, sizeof(unsigned long));
    datosBrutos = new Dato[N];
    ar.read((char*)datosBrutos, sizeof(Dato)*N);
    ar.close();

    cout << datosBrutos->Nombre[0] << endl;
}


int main(){
    Leer_archivo();
    return 0;
}