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
    ll n, a, b, c; cin >> n >> a >> b >> c;
    vector<vector<ll>> data(n, vector<ll>(n)); rep(i, n) rep(j, n) cin >> data[i][j];

    vector<ll> path(n);
    rep(i, n) path[i] = infl;

    //cout << "tst" << endl;
    vector<bool> flag(n);
    path[0] = 0;
    //flag[0] = true;
    min_priority_queue<int> que;
    //rep(i, n) cout << path[i] << endl;
    //cout << "tst" << endl;
    vector<int> root(n);
    rep(i, n) root[i] = i;

    rep(i, n){
        ll min = infl, min_j;
        rep(j, n){
            if(!flag[j] && min > path[j]) min = path[j], min_j = j;
        }
        flag[min_j] = true;//this
        rep(j, n){
            if(path[j] > path[min_j]+data[min_j][j]){//ここ書き方ある if文の中に入れる方法
                path[j] = path[min_j]+data[min_j][j];
                root[j] = min_j;
            }
        }
    }

    //最短経路の計算
    int f = n-1;
    vector<ll> ans;
    while(f != 0){
        ans.insert(ans.begin(), f);
        f = root[f];
    }
    ans.insert(ans.begin(), 0);

    //rep(i, ans.size()) cout << "ee" << ans[i] << endl;
    //rep(i, n) cout << root[i] << endl;

    int ans__ = ans.size();
    ll fans = infl;
    rep(i, ans__+1){
        ll memo = 0;
        rep(j, ans__-1){
            if(j >= i) memo += (data[ans[j]][ans[j+1]]*b + c);
            else memo += data[ans[j]][ans[j+1]]*a;
            //cout << memo << endl;
        }
        chmin(fans, memo);
    }
    cout << fans << endl;
    return 0;
}