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
    vector<int> ii(q), x(q); rep(i, q) cin >> ii[i] >> x[i];
    rep(i, q) ii[i]--;

    vector<int> b(n+1);
    rep(i, n) b[i] = a[i];
    b[n] = 2*inf;
    sort(b.begin(), b.end());
    // 挿入の順番
    
    set<int> st;
    rep(i, n){
        for(int j=b[i]+1; j<b[i+1]; j++){
            st.insert(j);
            if(st.size() == q) break;
        }
        if(st.size() == q) break;
    }

    multiset<int> must;
    rep(i, n){
        must.insert(a[i]);
    }

    rep(i, q){
        int num = a[ii[i]];
        a[ii[i]] = x[i];
        if(must.count(num) == 1){
            st.insert(num);
        }

        // 入れ替え
        auto itr = must.lower_bound(num);
        must.erase(itr);
        must.insert(x[i]);
        
        if(st.count(x[i])){
            auto itr = st.lower_bound(x[i]);
            st.erase(itr);
        }
        cout << *st.begin() << endl;
        /*for(auto v : a) cout << v << " ";
        cout << endl;
        for(auto v : st) cout << v << " ";
        cout << endl;
        for(auto v : must) cout << v << " ";
        cout << endl;*/
    }

    return 0;
}