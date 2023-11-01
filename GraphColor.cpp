#include<bits/stdc++.h>
using namespace std;
const int V = 10000;
int G[V][V];
int x[V];
int n , m ;
bool graphColoring(int vertex);
bool isSafe(int k, int clr);

bool graphColoring(int vertex){
     if(vertex == n) return true;
     for(int clr = 1; clr <= m; clr++){
        if(isSafe(vertex, clr)){
            x[vertex] = clr;
            if(graphColoring(vertex + 1) == true) return true;
            x[vertex] = 0;
        }
     }
     return false;
}
bool isSafe(int k, int clr){
    for(int i = 0; i < n; i++){
        if(G[k][i] && clr == x[i]) return false;
    }
    return true;
}
int main(){
    int e; cin >> n >> m >> e;
    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        G[u][v] = 1; G[v][u] = 1;
    }
    cout << "Adj Matrix: \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    graphColoring(0);
    cout << endl;
    int cnt = count(x,x+n,0);
    if(cnt > 0) cout << "Impossible\n";
    else {
        for(int i = 0; i < n; i++) cout << i << " : " << x[i] << endl;
        cout << endl;
    }

}
//4 3 5
//3 2
//3 0
//2 0
//0 1
//1 2
