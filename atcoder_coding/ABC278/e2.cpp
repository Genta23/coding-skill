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
    int h, w, n, y, x; cin >> h >> w >> n >> y >> x;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j], a[i][j]--;

    vector<vector<int>> c_pos(n, vector<int>(4)); // y_min, y_max, x_min, x_max;
    rep(i, n) c_pos[i][0] = inf, c_pos[i][2] = inf;

    rep(i, h){
        rep(j, w){
            chmin(c_pos[a[i][j]][0], (int)i);
            chmax(c_pos[a[i][j]][1], (int)i);
            chmin(c_pos[a[i][j]][2], (int)j);
            chmax(c_pos[a[i][j]][3], (int)j);
        }
    }
    rep(i, n) c_pos[i][1]++, c_pos[i][3]++;

    set<int> st;
    rep(i, h) rep(j, w) st.insert(a[i][j]);
    int sum = st.size();

    rep(i, h-y+1){
        rep(j, w-x+1){
            int cnt = 0;
            // y_min = i, y_max = i+y, x_min = j, x_max = j+x;
            rep(k, n){
                if(c_pos[k][0] == inf) continue;
                if(i <= c_pos[k][0] && c_pos[k][1] <= i+y && j <= c_pos[k][2] && c_pos[k][3] <= j+x){
                    cnt++;
                }
            }
            cout << sum - cnt << " ";
        }
        cout << endl;
    }
    return 0;
}