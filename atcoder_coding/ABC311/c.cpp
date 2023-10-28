#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

int main(){
    int n; cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i], a[i]--;

    set<int> st;
    int v = 0;
    st.insert(v);
    int cnt = 1;
    while(1){
        if(st.size() != cnt){
            break;
        }
        st.insert(a[v]);
        v = a[v];
        cnt++;
    }

    vector<int> ans;
    ans.push_back(v);
    int f = v;
    v = a[v];
    while(v != f){
        ans.push_back(v);
        v = a[v];
    }

    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
    return 0;
}