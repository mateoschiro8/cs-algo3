#ifndef P1_EJ10_H
#define P1_EJ10_H

#include <vector>
using namespace std;

int cajas(vector<int> &pesos, vector<int> &soportes, vector<vector<int>> &memo, int i, int k) {
    
    // Si me pasé de la ultima caja, devuelvo 0 
    if(i == pesos.size())
        return 0;

    else {

        if(memo[i][k] == - 1) {
            // Si no me paso del peso poniendo la caja
            if(pesos[i] < k) {
                int poner = 1 + cajas(pesos, soportes, memo, i + 1, min(k - pesos[i], soportes[i]));
                int noPoner = cajas(pesos, soportes, memo, i + 1, k);

                memo[i][k] = max(poner, noPoner);
            }

            // Si me paso, no la pongo
            else   
                memo[i][k] = cajas(pesos, soportes, memo, i + 1, k); 

        }
        return memo[i][k];

    }
}


void pruebaEj10() {
    
    vector<int> pesos = {19, 7, 5, 6, 1};
    vector<int> soportes = {15, 13, 7, 8, 2};


    int sumaPesos = 0;
    for(int i = 0; i < pesos.size(); i++)
        sumaPesos += pesos[i];
    
    vector<vector<int>> memo(pesos.size(), vector<int>(sumaPesos + 1, -1));
    
    int res = cajas(pesos, soportes, memo, 0, sumaPesos);

    cout << "La mayor pila posible es de tamaño " << res << endl;

}

// Manera esquizofrénica y rebuscada que devuelve la secuencia de cajas en lugar de la cantidad
/*
bool sePasa(const vector<int> &pesos, const vector<int> &soportes, const vector<int> &pila) {
    bool sePasa = false;
    int sum = 0;
    for (int i = pila.size() - 1; i > 0 && !sePasa; i--) {
        sum = sum + pesos[pila[i]];
        if (sum > soportes[pila[i - 1]])
            sePasa = true;
    }
    return sePasa;
}

void cajas(const vector<int> &pesos, const vector<int> &soportes, vector<int> &pila, vector<int> &res) {
    if (pila.size() > res.size()) 
        res = pila;
    for (int i = pila[pila.size() - 1] + 1; i < pesos.size(); i++) {
            pila.push_back(i);
            if(!sePasa(pesos, soportes, pila))
                cajas(pesos, soportes, pila, res);
            pila.pop_back();
    }
    
}

vector<int> cajasAux(const vector<int> &pesos, const vector<int> &soportes) {
    
    vector<int> res = {}; 
    vector<int> pila;

    for (int i = 0; i < pesos.size(); i++) {
        pila.push_back(i);
        cajas(pesos, soportes, pila, res);
        pila.pop_back();
    }
    return res;
}
*/

#endif //P1_EJ10_H