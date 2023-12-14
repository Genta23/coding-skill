#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
#include <bitset>
#include <tuple>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;


int main(){
    // キューを使用するもの
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    queue<int> que;
    rep(i, n-m+1){
        bool flag = true;
        rep(j, m) if(s[i+j] != t[j]) flag = false;
        if(flag) que.push(i);
    }

    while(!que.empty()){
        int v = que.front(); que.pop();
        //cout << v << endl;
        rep(i, m){
            s[v+i] = '#';
        }
        for(int i=1; i<m; i++){
            if(v+i < n-m+1){
                bool flag = false;
                rep(j, m) if(s[v+i+j] != '#') flag = true;
                rep(j, m) if(s[v+i+j] != '#' && s[v+i+j] != t[j]) flag = false;
                if(flag) que.push(v+i);
            }
        }
        for(int i=1; i<m; i++){
            if(v-i >= 0){
                bool flag = false;
                rep(j, m) if(s[v-i+j] != '#') flag = true;
                rep(j, m) if(s[v-i+j] != '#' && s[v-i+j] != t[j]) flag = false;
                if(flag) que.push(v-i);
            }
        }
    }

    /*rep(i, n) cout << s[i];
    cout << endl;*/

    rep(i, n){
        if(s[i] != '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}