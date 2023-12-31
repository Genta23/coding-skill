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
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    vector<int> t(n), x(n); rep(i, n) cin >> t[i] >> x[i];
    rep(i, n) x[i]--;

    /* 逆生成 */
    vector<int> e(n), ans(n);
    for(int i=n-1; i>=0; i--){
        if(t[i] == 2){
            e[x[i]]++;
        }
        else{
            if(e[x[i]] > 0){
                ans[i] = 1;
                e[x[i]]--;
            }
        }
    }

    /* 撃退可能かの判定 */
    bool flag = true;
    rep(i, n) if(e[i] != 0) flag = false;
    if(flag){
        int num = 0;
        int max = 0;
        rep(i, n){
            if(t[i] == 1 && ans[i] == 1) num++;
            else if(t[i] == 2) num--;

            /* ポーションの最適数を取得 */
            chmax(max, num);
        }
        cout << max << endl;

        rep(i, n) if(t[i] == 1) cout << ans[i] << " ";
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}