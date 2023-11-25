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
struct Data{
  ll cnt = 0, h = -1, t = -1;
};

Data mem[300007];
int main(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    // ちょっとアルゴリズム改変したらすぐに解けそう
    // 正直今は眠い
    ll ans = 0;
    rep(i, n){
      mem[a[i]].cnt++;
      if(mem[a[i]].h == -1){
        mem[a[i]].h = i;
      }
      else{
        mem[a[i]].t = i;
        ans += ((mem[a[i]].t - mem[a[i]].h + 1) - mem[a[i]].cnt);
      }
    }
    cout << ans << endl;
    return 0;
}