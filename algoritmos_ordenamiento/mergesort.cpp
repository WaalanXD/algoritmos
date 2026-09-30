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

// Función para fusionar dos sub-arreglos
void mezclar(std::vector<std::string> &v, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    // Crear arreglos temporales

    std::vector<std::string> L(n1);
    std::vector<std::string> R(n2);

    // Copiar datos a los arreglos temporales

    for (int i = 0; i < n1; i++)
        L[i] = v[izquierda + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[medio + 1 + j];




    // Fusionar los arreglos temporales de nuevo en el vector
    int i = 0;
    int j = 0;
    int k = izquierda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[]
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }


}

// Función principal de Merge Sort
void mergeSort(std::vector<std::string> &v, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Ordenar la primera y la segunda mitad
        mergeSort(v, izquierda, medio);
        mergeSort(v, medio + 1, derecha);

        // Fusionar las mitades ordenadas
        mezclar(v, izquierda, medio, derecha);
    }
}

// Función para imprimir el vector
void printArray(std::vector<std::string> &v, int size) {
    for (int i = 0; i < size; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

// Función principal para probar el algoritmo
int main() {
    std::vector<std::string> palabras = cargarPalabras("../dataset.txt");

    if (palabras.empty()) {
        std::cerr << "No se cargaron palabras, revisa la ruta del dataset." << std::endl;
        return 1;
    }

    std::cout << "Palabras cargadas: " << palabras.size() << std::endl;

    int tamaño = palabras.size();

    auto inicio = std::chrono::high_resolution_clock::now();

    mergeSort(palabras, 0, tamaño - 1);

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;

    std::cout << "Tiempo de ejecucion (mergesort): " << duracion.count() << " ms" << std::endl;

    std::cout << "Primeras 10 palabras ordenadas:" << std::endl;
    for (int i = 0; i < 10 && i < tamaño; i++)
        std::cout << palabras[i] << std::endl;

    return 0;
}
