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
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    rep(i, n) cin >> a[i];

    a[n] = 0; //ボトムを作る これによって、kより先に楽しさがなくなる例外処理もループにまとめることができる
    sort(a.begin(), a.end(), std::greater<int>{});
    ll cnt = 0;
    ll ans = 0;
    rep(i, n){
        cnt++;
        if(k - (a[i] - a[i+1]) * cnt > 0){
            k -= (a[i] - a[i+1]) * cnt;

            ans += ((ll) (a[i]*(a[i]+1))/2 - (ll) (a[i+1]*(a[i+1]+1))/2)*cnt;
        }
        else{
            //ここに入った時点でループは終了
            int p = k / cnt, q = k % cnt;
            
            ans += (ll) ((a[i]*(a[i]+1))/2 - (ll) ((a[i]-p)*(a[i]-p+1))/2)*cnt;
            ans += (ll) (a[i]-p) * q;

            //ここめっちゃ重要なのに書き忘れていた
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}