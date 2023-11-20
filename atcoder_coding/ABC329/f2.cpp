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
    int n, q; cin >> n >> q;
    vector<int> c(n); rep(i, n) cin >> c[i];

    vector<set<int>> data(n);
    rep(i, n){
        data[i].insert(c[i]);
    }

    rep(i, q){
        int a, b; cin >> a >> b;
        a--, b--;

        if(data[a].size() > data[b].size()){
            /*set<int> tmp;
            tmp = data[a];
            data[a] = data[b];
            data[b] = tmp;*/
            swap(data[a], data[b]);
        }

        data[b].insert(data[a].begin(), data[a].end());
        data[a].clear();

        cout << data[b].size() << endl;
    }
    return 0;
}