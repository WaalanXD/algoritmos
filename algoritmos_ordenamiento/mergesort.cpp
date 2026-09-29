#include <iostream>
#include <vector>
// Función para fusionar dos sub-arreglos
void mezclar(std::vector<int> &v, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    // Crear arreglos temporales

    std::vector<int> L(n1);
    std::vector<int> R(n2);

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
void mergeSort(std::vector<int> &v, int izquierda, int derecha) {
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
void printArray(std::vector<int> &v, int size) {
    for (int i = 0; i < size; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

// Función principal para probar el algoritmo
int main() {
    std::vector<int> datos = {38, 27, 43, 3, 9, 82, 10};
    int tamaño = datos.size();

    std::cout << "Arreglo original: ";
    printArray(datos, tamaño);

    mergeSort(datos, 0, tamaño - 1);

    std::cout << "Arreglo ordenado: ";
    printArray(datos, tamaño);

    return 0;
}