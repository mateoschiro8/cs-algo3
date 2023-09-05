
#ifndef P1_EJ3_H
#define P1_EJ3_H

#include <vector>
using namespace std;

int sumaMatriz(vector<vector<int>>& mat, vector<int>& v) {
    int c = 0;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            c = c + mat[v[i - 1]][v[j - 1]];
        }
    }
    return c;
}

void maxSumaMatriz(vector<vector<int>>& mat, vector<int>& v, int i, int k, int& maxSuma, vector<int>& mejorSubc) {

    // Si ya formé un subconjunto de tamaño k o no tengo más elementos para agregar
    if(v.size() == k || i == mat.size() + 1) {

        // Si la suma es mayor, lo guardo
        int s1 = sumaMatriz(mat, v);
        if(s1 > maxSuma) {
            maxSuma = s1;
            mejorSubc = v;
        }
        return;
    } else {
        // Pruebo agregando el valor que estoy considerando
        v.push_back(i);
        maxSumaMatriz(mat, v, i + 1, k, maxSuma, mejorSubc);
        v.pop_back();

        // Pruebo sin agregar el valor que estoy considerando
        maxSumaMatriz(mat, v, i + 1, k, maxSuma, mejorSubc);
    }
}

void pruebaEj3() {
    vector<vector<int>> mat = {{  0, 10, 10,  1},
                               { 10,  0,  5,  2},
                               { 10,  5,  0,  1},
                               {  1,  2,  1,  0}};

    vector<int> p1 = {};
    vector<int> mejorSubc = {};
    int maxSuma = 0;
    maxSumaMatriz(mat, p1, 1, 3, maxSuma, mejorSubc);

    for (int i = 0; i < mejorSubc.size(); ++i) {
        cout << mejorSubc[i] << " ";
    }
}

#endif //P1_EJ3_H
