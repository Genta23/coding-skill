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
int n, m; string s, t;

void dfs(int a, int b){
    bool flag = true;
    rep(i, m){
        if(i < b){
            if(s[a+i] != '#') flag = false;
        }
        else{
            if(s[a+i] != t[i]) flag = false;
        }
    }
    if(flag){
        rep(i, m) s[a+i] = '#';
        for(int j=1; j<m; j++) dfs(a+(m-j), j);
    }

    flag = true;
    rep(i, m){
        if(s[a+i] == '#') continue;
        else{
            if(s[a+i] != t[i]) flag = false;
        }
    }
    if(flag){
        rep(i, m) s[a+i] = '#';
    }
}

int main(){
    cin >> n >> m >> s >> t;

    rep(i, n-m+1){
        bool flag = true;
        rep(j, m) if(s[i+j] != t[j]) flag = false;
        if(flag){
            rep(j, m) s[i+j] = '#';
            for(int j=1; j<m; j++) dfs(i+(m-j), j);
        }
    }

    
}