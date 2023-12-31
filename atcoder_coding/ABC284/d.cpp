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

/*  make_is_prime(N)
    入力：整数 N
    出力：N までの数字が素数か判定したベクトル（i番目がtrueならiは素数）
    計算量：O(nloglogn)
*/
vector<bool> make_is_prime(int N) {
    vector<bool> prime(N + 1, true);
    if (N >= 0) prime[0] = false;
    if (N >= 1) prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}

int main(){
    int t; cin >> t;
    vector<ll> x(t); rep(i, t) cin >> x[i];
    int size = 3000007;
    vector<bool> f = make_is_prime(size);

    rep(i, t){
        ll p = 0, q = 0;
        rep(j, f.size()){
            if(f[j]){
                if(x[i]%j == 0){
                    x[i] /= j;
                    if(x[i]%j == 0){
                        p = j;
                        x[i] /= j;
                        q = x[i];
                    }
                    else{
                        q = j;
                        ll l = 1, r = 3e9; // これがデカすぎてOFしている 絶妙な部分でエラー起きたかも
                        while(l + 1 < r){
                            ll v = (l+r)/2;
                            if(v*v <= x[i]){ // イコールが入っている部分の数値を採用する
                                l = v;
                            }
                            else{
                                r = v;
                            }
                            //cout << l << " " << r << endl;
                        }
                        p = l;
                    }
                    break;
                }
            }
        }
        cout << p << " " << q << endl;
    }
    return 0;
}