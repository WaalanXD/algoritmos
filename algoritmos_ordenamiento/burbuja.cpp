//
// Created by kenny on 3/09/2026.
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

void burbuja(std::vector<std::string> &v) {


    bool hubo_cambio = false;

    for (size_t i = 0; i+1 < v.size(); i++) {

        if (!hubo_cambio && i > 0) {

            break;
        }
        hubo_cambio = false;

        for (size_t j = 0; j < v.size()-i-1; j++) {

            if (v[j] > v[j+1]) {

                std::string temporal = v[j];
                v[j] = v[j+1];
                v[j+1] = temporal;
                hubo_cambio = true;


            }

        }

    }


}

int main() {

    std::vector<std::string> palabras = cargarPalabras("../dataset.txt");

    if (palabras.empty()) {
        std::cerr << "No se cargaron palabras, revisa la ruta del dataset." << std::endl;
        return 1;
    }

    std::cout << "Palabras cargadas: " << palabras.size() << std::endl;

    auto inicio = std::chrono::high_resolution_clock::now();

    burbuja(palabras);

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;

    std::cout << "Tiempo de ejecucion (burbuja): " << duracion.count() << " ms" << std::endl;

    std::cout << "Primeras 10 palabras ordenadas:" << std::endl;
    for (size_t i = 0; i < 10 && i < palabras.size(); i++) {
        std::cout << palabras[i] << std::endl;
    }

    return 0;
}
