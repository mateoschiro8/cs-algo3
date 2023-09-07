#ifndef P1_EJ2_H
#define P1_EJ2_H

#include <vector>
using namespace std;

bool esMagico(vector<vector<int>>& cuad, int n) {

    // Calculo cuanto tiene que dar la suma (propiedad de cuadrados mágicos)
    int suma = (n * n * n + n) / 2;

    // Verifico las filas y columnas
    for (int i = 0; i < n; ++i) {
        int sumaFila = 0;
        int sumaColumna = 0;

        for (int j = 0; j < n; ++j) {
            sumaFila += cuad[i][j];
            sumaColumna += cuad[j][i];
        }

        if (sumaFila != suma || sumaColumna != suma) {
            return false;
        }
    }

    // Verifico la diagonal principal y secundaria
    int sumaDiagonalPrincipal = 0;
    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < n; ++i) {
        sumaDiagonalPrincipal += cuad[i][i];
        sumaDiagonalSecundaria += cuad[i][n - 1 - i];
    }

    if (sumaDiagonalPrincipal != suma || sumaDiagonalSecundaria != suma) {
        return false;
    }

    return true;
}

bool estaEnCuad(vector<vector<int>>& cuad, int n, int k) {
    // Recorro todas las casillas
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(cuad[i][j] == k)
                return true;
        }
    }
    return false;
}

void mostrarCuadrado(vector<vector<int>>& cuad, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cuad[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void cuadradoMagico(vector<vector<int>>& cuad, int n, int i, int j) {

    // Calculo el número mágico (propiedad de cuadrados mágicos)
    int magico = (n * n * n + n) / 2;

    // Si llegué al final
    if (i == n) {
        if (esMagico(cuad, n)) {
            mostrarCuadrado(cuad, n);
        }
        return;
    }

    // Calculo la nueva posición
    int nuevoI = i;
    int nuevoJ = j + 1;
    if (nuevoJ == n) {
        nuevoI++;
        nuevoJ = 0;
    }

    // Busco que elemento está disponible, lo agrego y pruebo. Si no puedo formar un cuadrado mágico,
    // lo vuelvo a 0 y hago backtracking
    for (int k = 1; k <= n * n; ++k) {
        if (!estaEnCuad(cuad, n, k)) {

            // Antes de agregarlo, verifico que las sumas parciales de la fila no supere el numero mágico
            // Se puede agregar que la suma parcial de la columna tampoco lo haga
            int cant2 = 0;
            for (int l = 0; l < n; ++l) {
                if(nuevoI < n)
                    cant2 = cant2 + cuad[nuevoI][l];
            }
            if(cant2 + k <= magico) {
                cuad[i][j] = k;
                cuadradoMagico(cuad, n, nuevoI, nuevoJ);
                cuad[i][j] = 0;  // Backtracking
            }
        }
    }
}

void pruebaEj2() {
// En este me ayudó Mr. Gpt
    int n = 3;  // No existe solución para n = 2
    vector<vector<int>> cuad(n, vector<int>(n, 0));
    cuadradoMagico(cuad, n, 0, 0);
}

#endif //P1_EJ2_H
