#ifndef KNSK
#define KNSK

#include <vector>
using namespace std;

int knapsack(int k, int D, vector<int>& p, vector<int>& b, vector<vector<int>>& m) {
     
    // cout << k << " " << D << endl;
    if(k == 0)
        return m[k][D] = 0;

    if(m[k][D] == -1) { 
        if(k > 0 && p[k - 1] > D)
            m[k][D] = knapsack(k - 1, D, p, b, m);
        else
            m[k][D] = max(knapsack(k - 1, D, p, b, m), b[k - 1] + knapsack(k - 1, D - p[k - 1], p, b, m)); 
    }

    return m[k][D];
}

void pruebaKnapsack() {

    vector<int> pesos = {1, 2,  5,  6,  7};
    vector<int> beneficios = {1, 6, 18, 22, 28};
    int k = pesos.size();
    int capacidad = 11;

    vector<vector<int>> memo(k + 1, vector<int>(capacidad + 1, -1));

    cout << knapsack(k, capacidad, pesos, beneficios, memo) << endl;

    /*
    for(int i = 0; i < memo.size(); i++) {
        for(int j = 0; j < memo[0].size(); j++) { 
            knapsack(i, j, pesos, beneficios, memo); 
        }
    }
    */

    for(int i = 0; i < memo.size(); i++) {
        for(int j = 0; j < memo[0].size(); j++) {
            int k = memo[i][j];
            if(k < 10 && k >= 0)
                cout << " " << k << " ";
            else
                cout << k << " ";
        }
        cout << endl;
    }
}

#endif //KNSK
