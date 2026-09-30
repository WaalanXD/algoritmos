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

void insercion(std::vector<std::string> &v) { // metodo que recive un vector de strings

    for (size_t i = 1; i < v.size(); i++) { // recorremos el vector separando v[0] como una sublista ordenada por definición

        std::string carta = v[i]; // guardamos la carta actual
        long long j = static_cast<long long>(i)-1; // guardamos la posicion anterior a la carta actual (long long porque debe poder llegar a -1)

        while (j >= 0 && v[j] > carta) { // mientras el indice iterable anterior no sea menor que cero y su dato sea mayor a la carta
            // Este ciclo se cumplira solamente si al menos el dato v[j] actual debe ser cambiado de posición a la derecha de la carta

            // Pasamos los elementos mayores de la sublista ordenada donde pertenece v[j] hacia la derecha de la carta

            // primero se copia (pasa a la derecha) el dato de v[j] en v[j+1], si tuvieramos [1,0] pasaria a [1,1]

            v[j+1] = v[j];

            // ahora tenemos que interar hacia la izquierda el indice j para la sublista ordenada

            j--;

        }

        // Antes de pasar a la siguiente comparación i++:
        // Nos queda un espacio justo cuyo dato clonamos y traladamos a la derecha en la posición v[j+1] actual
        // Esto sucede despues de que se saliera del ciclo while
        // Asi que simplemente insertamos nuestra carta en el hueco donde corresponde

        v[j+1] = carta;

        // finalmente, vamos a repetir el primer ciclo para ir recorriendo las siguientes cartas de la derecha del array
        // que buscaremos insertar en la posición adecuada de la sublista de la izquierda repitiendo el proceso anterior

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

    insercion(palabras);

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;

    std::cout << "Tiempo de ejecucion (insercion): " << duracion.count() << " ms" << std::endl;

    std::cout << "Primeras 10 palabras ordenadas:" << std::endl;
    for (size_t i = 0; i < 10 && i < palabras.size(); i++) {
        std::cout << palabras[i] << std::endl;
    }

    return 0;
}
