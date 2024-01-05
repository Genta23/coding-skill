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

    vector<int> c(n);
    int cnt = 0;
    rep(i, h) rep(j, w){
        if(c[a[i][j]] == 0) cnt++;
        c[a[i][j]]++;
    }

    rep(i, h-y+1){
        int t_cnt = cnt;
        vector<int> t_c = c;
        rep(j, y){
            rep(k, x){
                t_c[a[i+j][k]]--;
                if(t_c[a[i+j][k]] == 0) t_cnt--;
            }
        }
        cout << t_cnt << " ";

        rep(j, w-x){
            // jとj+xについて調べる
            rep(k, y){
                if(t_c[a[i+k][j]] == 0) t_cnt++;
                t_c[a[i+k][j]]++;
            }
            rep(k, y){
                t_c[a[i+k][j+x]]--;
                if(t_c[a[i+k][j+x]] == 0) t_cnt--;
            }
            cout << t_cnt << " ";
        }
        cout << endl;
    }
    return 0;
}