#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<pii>vii;
typedef vector<pll>vll;
#define PB push_back
#define F first
#define S second
const ll infLL = 9000000000000000;
const int mx = 1e5 + 123;
vii adj[mx]; /// array , index e vector thakbe jar type pair
ll dist[mx];
void dijkastra(int s, int n){
    for(int i = 0; i <=n; i++) dist[i] = infLL;
    dist[s] = 0;
    priority_queue<pll,vll,greater<pll>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();
        if(dist[u] < curD ) continue;
        for(int i = 0; i <adj[u].size();i++){
            pll p = adj[u][i];
            int v = p.F;
            ll w = p.S;
            if(curD + w < dist[v]){
                dist[v] = curD + w;
                pq.push({dist[v],v});
            }
        }
    }

}
int main(){
    int n,e; cin >> n >> e;
    for(int i = 1; i <= e; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].PB({v,w});
        adj[v].PB({u,w});
    }
    dijkastra(0,n);
    for(int i = 0; i <n; i++) cout << i << ": " << dist[i] << endl;

}
//5 7
//1 3 3
//1 2 2
//1 4 6
//2 0 6
//2 3 7
//0 4 3
//3 4 5
