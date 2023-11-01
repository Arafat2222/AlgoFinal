#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> rabin_karp(string &s,string &t){
    int p = 31;
    int m = 1e9 + 9;
    int  S = s.size(), T = t.size();
    vector<ll>p_pow(max(S,T)); p_pow[0] = 1;
    /// (31^0 % m) + (31^1 % m) + (31^2 % m) + .....
    for(int i = 1; i < (int)p_pow.size(); i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
    }
    vector<ll> h(T+1,0);///hash for Text
    for(int i = 0; i < T; i++){
        h[i+1] = (h[i] + (t[i] - 'a' + 1)* p_pow[i]) % m;
    }
    ll h_s = 0 ; /// pattern total hash value
    for(int i = 0; i < S; i++){
        h_s += ((s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    ///calculate index
    vector<int>occurrences;
    for(int i = 0; i + S - 1 < T; i++){
        ll cur_h = (h[i+S]+ m - h[i]) % m;
        if(cur_h == h_s * p_pow[i] % m){
            occurrences.push_back(i);
        }
    }
    return occurrences;

}
int main(){
    string pattern, text; cin >> pattern >> text;
    vector<int> ans = rabin_karp(pattern,text);
    for(int i = 0; i < ans.size();i++) cout << ans[i] << endl;
}

