//
// Created by kenny on 3/09/2026.
//

#include <iostream>
#include <vector>

void burbuja(std::vector<int> &v) {


    int hubo_cambio = false;

    for (int i = 0; i+1 < v.size(); i++) {

        if (!hubo_cambio && i > 0) {

            break;
        }
        hubo_cambio = false;

        for (int j = 0; j < v.size()-i-1; j++) {

            if (v[j] > v[j+1]) {

                int temporal = v[j];
                v[j] = v[j+1];
                v[j+1] = temporal;
                hubo_cambio = true;


            }

        }

    }


}

int main() {



}