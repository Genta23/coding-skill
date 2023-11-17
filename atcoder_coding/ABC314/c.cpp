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
    string s; cin >> s;
    vector<int> c(n);
    rep(i, n){
        int tmp; cin >> tmp;
        tmp--;
        c[i] = tmp;
    }

    vector<queue<char>> data(m);
    rep(i, n){
        data[c[i]].push(s[i]);
    }

    rep(i, m){
        rep(j, data[i].size()-1){
            char tmp = data[i].front();
            data[i].pop();
            data[i].push(tmp);
        }
    }

    string ans = "";
    rep(i, n){
        ans += data[c[i]].front();
        data[c[i]].pop();
    }

    cout << ans << endl;
    return 0;
}