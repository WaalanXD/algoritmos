//
// Created by kenny on 7/09/2026.
//


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

// Carga cada línea del archivo como un elemento de un vector<string>
std::vector<std::string> cargarPalabras(const std::string &rutaArchivo) {
    std::vector<std::string> palabras;
    std::ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << rutaArchivo << std::endl;
        return palabras;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) {
            palabras.push_back(linea);
        }
    }

    return palabras;
}

// Template para poder intercambiar tanto int como string (u otros tipos)
template <typename T>
void intercambiar(T &a, T &b) {
    T temporal = a;
    a = b;
    b = temporal;

}
int particion(std::vector<std::string> &v, int izquierda, int derecha) {

    // Mediana de 3
    int medio = (izquierda + derecha) / 2;

    if (v[medio] < v[izquierda]) {
        intercambiar(v[medio], v[izquierda]);
    }

    if (v[derecha] < v[izquierda]) {
        intercambiar(v[izquierda], v[derecha]);

    }

    if (v[derecha] < v[medio]) {
        intercambiar(v[derecha], v[medio]);
    }

    intercambiar(v[medio], v[derecha]);
    std::string pivote = v[derecha];

    int i = izquierda - 1;

    for (int j = izquierda; j <= derecha -1; j++) {
        if (v[j] < pivote) {
            i++;
            intercambiar(v[i], v[j]);

        }

    }

    intercambiar(v[i+1], v[derecha]);
    return i+1;









}


void quicksort(std::vector<std::string> &v, int izquierda, int derecha) {

    if (izquierda < derecha) {
        int indice_particion = particion(v, izquierda, derecha);
        quicksort(v, izquierda, indice_particion - 1);
        quicksort(v, indice_particion + 1, derecha);

    }
}



int main() {

    std::vector<std::string> palabras = cargarPalabras("../dataset.txt");

    if (palabras.empty()) {
        std::cerr << "No se cargaron palabras, revisa la ruta del dataset." << std::endl;
        return 1;
    }

    std::cout << "Palabras cargadas: " << palabras.size() << std::endl;

    int longitud = palabras.size();

    auto inicio = std::chrono::high_resolution_clock::now();

    quicksort(palabras, 0, longitud - 1);

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;

    std::cout << "Tiempo de ejecucion (quicksort): " << duracion.count() << " ms" << std::endl;

    std::cout << "Primeras 10 palabras ordenadas:" << std::endl;
    for (int i = 0; i < 10 && i < longitud; i++) {
        std::cout << palabras[i] << std::endl;
    }

    return 0;

}
