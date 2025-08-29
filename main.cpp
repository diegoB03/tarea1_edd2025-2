#include <iostream>
#include <fstream>
#include <string>
#include <cstring>   
using namespace std;

// ====== Estructura provista por la tarea ======
struct Dato{
    unsigned int Id;            // Id único por estudiante
    char Nombre[50];            // Nombre y apellido
    char Fecha_Nacimiento[11];  // Fecha de nacimiento YYYY/MM/DD
    int Notas[3];               // Notas de las 3 evaluaciones
    char Curso[7];              // Sigla del curso (p.ej., INF134)
    unsigned short VTR;         // Veces que ha rendido el ramo (1-3)
};

// ====== Variables globales mínimas ======
// Arreglo dinámico de datos y su cantidad
Dato* g_datos = NULL;
int   g_cantidad = 0;

// ====== Prototipos exigidos (se pueden ajustar, pero mantenemos nombres) ======
Dato* Leer_Archivo(const string &nombre_archivo);
void  Mostrar_Datos_Alumnos(Dato* datos, int n);   // utilidad: imprimir primeros 5
void  Eliminar_Duplicados(Dato*& datos, int& cantidad); // duplicados adyacentes por (Id,Curso)

// ====== Implementaciones ======

/*****
 * Procedimiento Leer_Archivo
 ******
 * Resumen:
 *   Carga el archivo binario `datos.dat` al arreglo dinámico de Dato.
 *   El archivo comienza con un unsigned long N (cantidad de registros),
 *   seguido de N structs Dato consecutivos.
 ******
 * Input:
 *   const string& nombre_archivo : ruta/nombre del archivo a abrir
 ******
 * Returns:
 *   Dato* : puntero a arreglo dinámico de tamaño N con los registros cargados.
 *****/
Dato* Leer_Archivo(const string &nombre_archivo){
    // Abrir archivo en modo binario
    ifstream ar(nombre_archivo.c_str(), ios::binary);
    if (!ar.is_open()){
        cerr << "No se pudo abrir el archivo: " << nombre_archivo << "\\n";
        g_cantidad = 0;
        return NULL;
    }

    // Leer N (la tarea especifica unsigned long)
    unsigned long Nul = 0;
    ar.read(reinterpret_cast<char*>(&Nul), sizeof(unsigned long));
    if (!ar.good()){
        cerr << "Error leyendo la cantidad de registros.\\n";
        g_cantidad = 0;
        ar.close();
        return NULL;
    }

    if (Nul == 0){
        g_cantidad = 0;
        ar.close();
        return NULL;
    }

    // Reservar memoria dinámica para N registros
    // Nota: g_cantidad se maneja como int para el resto de funciones
    if (Nul > 2147483647UL){ // cota de seguridad para int
        cerr << "Cantidad de registros demasiado grande.\\n";
        g_cantidad = 0;
        ar.close();
        return NULL;
    }
    g_cantidad = static_cast<int>(Nul);

    Dato* datos = new Dato[g_cantidad];
    // Leer los N registros consecutivos
    ar.read(reinterpret_cast<char*>(datos), sizeof(Dato) * g_cantidad);
    if (!ar.good()){
        cerr << "Error leyendo los registros.\\n";
        delete [] datos;
        g_cantidad = 0;
        ar.close();
        return NULL;
    }

    ar.close();
    return datos;
}

/*****
 * Procedimiento Mostrar_Datos_Alumnos
 ******
 * Resumen:
 *   Imprime por consola hasta los primeros 5 alumnos del arreglo, en un formato simple.
 ******
 * Input:
 *   Dato* datos : arreglo con los alumnos
 *   int n      : cantidad de alumnos en el arreglo
 ******
 * Returns:
 *   void
 *****/
void Mostrar_Datos_Alumnos(Dato* datos, int n){
    int tope = (n < 5) ? n : 5;
    cout << "---- Primeros " << tope << " alumnos cargados ----\\n";
    for (int i = 0; i < tope; ++i){
        cout << datos[i].Id << " | "
             << datos[i].Nombre << " | "
             << datos[i].Curso << " | "
             << datos[i].Fecha_Nacimiento << " | "
             << datos[i].VTR << " | "
             << datos[i].Notas[0] << " "
             << datos[i].Notas[1] << " "
             << datos[i].Notas[2] << "\\n";
    }
}

/*****
 * Procedimiento Eliminar_Duplicados
 ******
 * Resumen:
 *   Elimina duplicados ADYACENTES por par (Id, Curso) del arreglo.
 *   Re-dimensiona la memoria dinámica en el proceso.
 ******
 * Input:
 *   Dato*& datos     : referencia al puntero base del arreglo
 *   int& cantidad    : referencia a la cantidad actual de elementos
 ******
 * Returns:
 *   void (pero 'datos' y 'cantidad' cambian por referencia)
 *****/
void Eliminar_Duplicados(Dato*& datos, int& cantidad){
    if (datos == NULL || cantidad <= 1) return;

    // Primera pasada: contar cuántos quedan si quitamos duplicados adyacentes
    int nuevos = 1;
    for (int i = 1; i < cantidad; ++i){
        bool es_dup = (datos[i].Id == datos[i-1].Id) &&
                      (strncmp(datos[i].Curso, datos[i-1].Curso, 7) == 0);
        if (!es_dup) nuevos++;
    }

    if (nuevos == cantidad) return; // no había duplicados

    // Reservar nuevo arreglo
    Dato* filtrado = new Dato[nuevos];

    // Copiar dejando uno por cada grupo de adyacentes
    int j = 0;
    filtrado[j++] = datos[0];
    for (int i = 1; i < cantidad; ++i){
        bool es_dup = (datos[i].Id == datos[i-1].Id) &&
                      (strncmp(datos[i].Curso, datos[i-1].Curso, 7) == 0);
        if (!es_dup){
            filtrado[j++] = datos[i];
        }
    }

    // Reemplazar
    delete [] datos;
    datos = filtrado;
    cantidad = nuevos;
}

int main(){
    // 1) Cargar archivo
    g_datos = Leer_Archivo("datos.dat");
    if (g_datos == NULL || g_cantidad == 0){
        cerr << "No se cargaron datos.\\n";
        return 1;
    }

    // 2) Eliminar duplicados adyacentes
    Eliminar_Duplicados(g_datos, g_cantidad);

    // 3) Mostrar (solo para verificar lectura; en la tarea real se usa print.cpp)
    Mostrar_Datos_Alumnos(g_datos, g_cantidad);

    // Limpieza antes de salir (en la versión final, esto va al terminar el programa)
    delete [] g_datos;
    g_datos = NULL;
    g_cantidad = 0;
    return 0;
}
