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
    int n, m; cin >> n >> m;
    Graph g(n);
    vector<int> a(m), b(m);
    rep(i, m){
        int tmp; cin >> tmp;
        tmp--;
        a[i] = tmp;
    }
    rep(i, m){
        int tmp; cin >> tmp;
        tmp--;
        b[i] = tmp;
    }
    rep(i, m){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<int> flag(n, -1);
    rep(i, n){
        queue<int> que;
        if(flag[i] != -1) continue;
        flag[i] = 0;
        que.push(i);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int x : g[v]){
                if(flag[x] == -1){
                    flag[x] = (flag[v] + 1) % 2;
                    que.push(x);
                }
            }
        }
    }

    rep(i, m){
        if(flag[a[i]] == flag[b[i]]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}