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
    int n; cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i];
    
    vector<int> b(n);
    rep(i, n){
        b[a[i] - 1] = i;
    }

    set<int> st;
    st.insert(-1);
    st.insert(n);

    ll ans = 0;
    rep(i, n){
        st.insert(b[i]);
        auto itr = st.find(b[i]);
        auto next_itr = next(itr);
        auto prev_itr = prev(itr);
        //for(auto x : st) cout << x << " ";
        //cout << endl;
        //cout << "test : " << *prev_itr << " : " << *itr << " : " << *next_itr << endl;

        ans += (ll)(i+1) * (*next_itr - *itr) * (*itr - *prev_itr);
    }
    cout << ans << endl;
    return 0;
}