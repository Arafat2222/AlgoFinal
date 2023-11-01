#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 123;
vector<int>adj[mx];
map<int,int>mp;
bool vis[mx];
int lev[mx];
void bfs(int u){
    vis[u] = 1;
    lev[u] = 0;
    mp[u] = 0;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u  << ": Level " << lev[u]<< endl;
        for(int i = 0; i < adj[u].size();i++){
            int v = adj[u][i];
            if(!vis[v]){
                mp[v] = mp[u] + 1;
                lev[v] = lev[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }

    }

}
int main(){
    int n, e, s; cin >> n >> e >> s;
    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Connected Nodes:\n";
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n----BFS----\n";
    bfs(s);
    cout << "\n--View Level--\n";
    for(auto u:mp){
        cout << u.first << " : Level " <<u.second << endl;
    }


}
//5 4 1
//1 2
//2 3
//2 4
//1 5
