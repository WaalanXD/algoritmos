//
// Created by kenny on 3/09/2026.
//

#include <iostream>
#include <vector>


void insercion(std::vector<int> &v) { // metodo que recive un vector de enteros

    for (int i = 1; i < v.size(); i++) { // recorremos el vector separando v[0] como una sublista ordenada por definición

        int carta = v[i]; // guardamos la carta actual
        int j = i-1; // guardamos la posicion anterior a la carta actual

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


}