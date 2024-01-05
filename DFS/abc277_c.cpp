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
bool flag[400007];

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n); rep(i, n) cin >> a[i] >> b[i];

    set<int> temp; rep(i, n) temp.insert(a[i]), temp.insert(b[i]);

    vector<int> decomp;
    map<int, int> comp;
    int cnt = 0;
    for(int x : temp){
        comp[x] = cnt;
        decomp.push_back(x);
        cnt++;
    }
    /*for(auto itr = temp.begin(); itr != temp.end(); ++itr){
        int d = distance(temp.begin(), itr);
        comp[*itr] = d;
        decomp.push_back(*itr);
    }*/

    
    Graph g(2*n);
    rep(i, n){
        int ca = comp[a[i]], cb = comp[b[i]];
        g[ca].push_back(cb), g[cb].push_back(ca);
    }

    //初期地点から移動できない場合を除く
    if(decomp[0] != 1){
        cout << 1 << endl;
        return 0;
    }

    stack<int> st;
    st.push(0);
    flag[0] = true;
    int max = -1;
    while(!st.empty()){
        int v = st.top();
        st.pop();
        for(int x : g[v]){
            if(!flag[x]){
                st.push(x);
                flag[x] = true;
                chmax(max, x);
            }
        }
    }

    cout << decomp[max] << endl;
    return 0;
}