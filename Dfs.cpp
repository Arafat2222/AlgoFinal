#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int>adj[mx];
bool vis[mx];
int lev[mx];
map<int,int>mp;
void dfs(int u){
    vis[u] = 1;

    cout << u << ": Level " << lev[u] << endl;
    for(int i = 0; i < adj[u].size();i++){
        int v = adj[u][i];
        if(!vis[v]){
            vis[v] = 1;
            lev[v] = lev[u] + 1;
            mp[v] = mp[u] + 1;
            dfs(v);
        }
    }

}
int main(){
    int n, e, s; cin >> n >> e >> s;
    for(int i = 1; i <= e; i++){
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "--Connected Nodes--\n";
    for(int i = 1; i <=n; i++){
        cout << i << ": ";
        for(auto u : adj[i]){
            cout << u << " ";
        }
        cout << endl;
    }
    cout << " ----DFS---- \n";
    dfs(s);
    mp[s] = 0;
    cout << "--Level View--\n";
    for(auto u:mp){
        cout << u.first << ": Level " << u.second << endl;
    }
    cout << endl;
}
//5 4 1
//1 2
//2 3
//2 4
//1 5
