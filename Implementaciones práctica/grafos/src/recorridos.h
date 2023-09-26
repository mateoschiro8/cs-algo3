#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int v, vector<vector<int>>& aristas, vector<bool>& visitado) {
    visitado[v] = true;
    cout << " " << v << ",";
    for(int u : aristas[v]) {
        if(!visitado[u])
            dfs(u, aristas, visitado);
    }

}

void bfs(int v, vector<vector<int>>& aristas, vector<bool>& visitado) {
    visitado[v] = true;
    cout << " " << v << ",";
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        for(int u : aristas[s]) {
            if(!visitado[u]) {
                visitado[u] = true;
                cout << " " << u << ",";
                q.push(u);
            }
        }

    }

}

void recorrer() {

    vector<vector<int>> aristas = {{1}, {0,2,5}, {1,3,4,6}, {2,6}, {2,8,9}, {1}, {2,3,7,8}, {6,8}, {4,6,7}, {4}};
    

    vector<bool> visitado1(aristas.size(), false);
    cout << "Recorrido DFS " << endl;
    cout << "Pasé por: ";
    dfs(4, aristas, visitado1);
    cout << endl;

    vector<bool> visitado2(aristas.size(), false);
    cout << "Recorrido BFS " << endl;
    cout << "Pasé por: ";
    bfs(4, aristas, visitado2);
    cout << endl;
}