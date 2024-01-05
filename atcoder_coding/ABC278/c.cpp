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
#include <iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (ll i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(q), b(q), t(q); rep(i, q) cin >> t[i] >> a[i] >> b[i];

    set<pair<int, int>> st;
    rep(i, q){
        if(t[i] == 1){
            st.insert({a[i], b[i]});
        }
        else if(t[i] == 2){
            st.erase({a[i], b[i]});
        }
        else if(t[i] == 3){
            auto it1 = st.find({a[i], b[i]});
            auto it2 = st.find({b[i], a[i]});

            if(it1 != st.end() && it2 != st.end()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}