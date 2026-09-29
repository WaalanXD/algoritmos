//
// Created by kenny on 7/09/2026.
//


#include <iostream>
#include <vector>



void intercambiar(int &a, int &b) {
    int temporal = a;
    a = b;
    b = temporal;

}
int particion(std::vector<int> &v, int izquierda, int derecha) {

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
    int pivote = v[derecha];

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


void quicksort(std::vector<int> &v, int izquierda, int derecha) {

    if (izquierda < derecha) {
        int indice_particion = particion(v, izquierda, derecha);
        quicksort(v, izquierda, indice_particion - 1);
        quicksort(v, indice_particion + 1, derecha);

    }
}



int main() {

    std::vector<int> v = {2,5,3,1,4};
    int longitud = v.size();
    quicksort(v, 0, longitud - 1);
    for (int i = 0; i < longitud; i++) {
        std::cout << v[i] << " ";
    }
    return 0;

}