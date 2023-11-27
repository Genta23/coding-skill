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
    vector<int> a(n); rep(i, n) cin >> a[i];
    vector<int> k(n), x(n);
    rep(i, q){
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        tmp1--;
        k[i] = tmp1, x[i] = tmp2;
    }

    vector<int> b(n+1, 0);
    rep(i, n){
        if(a[i] <= n){
            b[a[i]]++;
        }
    }

    set<int> st;
    rep(i, n+1){
        if(b[i] == 0) st.insert(i);
    }

    rep(i, q){
        int index = k[i];
        int out = a[index];
        int in = x[i];

        if(in <= n){
            if(b[in] == 0){
                st.erase(in);
            }
            b[in]++;
        }

        if(out <= n){
            b[out]--;
            if(b[out] == 0){
                st.insert(out);
            }
        }

        a[index] = in;
        cout << *st.begin() << endl;
    }

    return 0;
}