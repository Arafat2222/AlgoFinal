#include<bits/stdc++.h>
using namespace std;
int PD45[100],MD45[100],row[100],n,ans[100];
bool chk = true;
void nQueen(int column){
    if(column > n){
       chk = false;
        for(int i = 1; i <=n; i++) cout << ans[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 1; i <=n; i++){
        if(!row[i] && !PD45[i+column] && !MD45[i-column+n]){
            ans[column] = i;
            PD45[i+column] = 1;
            MD45[i-column+n] = 1;
            row[i] = 1;
            nQueen(column+1);
            if(!chk) return;
            PD45[i+column] = 0;
            MD45[i-column+n] = 0;
            row[i] = 0;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        chk = true;
        if(n == 2 || n == 3){cout << "Not Possible\n"; continue;}
        memset(PD45,0,sizeof(PD45));
        memset(MD45,0,sizeof(MD45));
        memset(row,0,sizeof(row));
        nQueen(1);
    }
}
