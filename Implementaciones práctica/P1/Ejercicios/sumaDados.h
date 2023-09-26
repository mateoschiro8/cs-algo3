#include <iostream>
#include <vector>

using namespace std;


// O(n * k * min(s, nk))
int sumaDados(vector<vector<vector<int>>>& memo, int i, int j, int l) {
    if(j < 0 || i == 0 && j != 0 || j == 0 && i > 0)
        return 0;
    
    if(i == 0 && j == 0)
        return 1;

    if(memo[i][j][l] == -1) {
        int res = 0;
        for(int t = 1; t <= l; t++)
            res += sumaDados(memo, i - 1, j - t, t);
        memo[i][j][l] = res;
    }

    return memo[i][j][l];

}   

void pruebaSumaDados() {

    int n = 3;
    int k = 4;
    int s = 6;
    
    vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(s + 1, vector<int>(k + 1, -1)));    

    cout << "La cantidad de formas de sumar " << s << " con " 
            << n << " dados de " << k << " caras es: " << sumaDados(memo, n, s, k) << endl; 


}

