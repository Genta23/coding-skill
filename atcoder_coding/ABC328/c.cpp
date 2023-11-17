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
    string s; cin >> s;
    vector<int> l(q), r(q);
    rep(i, q){
        int s, t; cin >> s >> t;
        s--; t--;
        l[i] = s;
        r[i] = t;
    }

    int cnt = 0;
    vector<int> counter(n);
    counter[0] = 0;
    for(int i=1; i<=n; i++){
        if(s[i] == s[i-1]){
            counter[i] = cnt;
        }
        else{
            cnt++;
            counter[i] = cnt;
        }
    }

    //rep(i, n) cout << counter[i] << " ";

    rep(i, q){
        cout << (r[i] - l[i]) - (counter[r[i]] - counter[l[i]]) << endl;
    }
    return 0;
}