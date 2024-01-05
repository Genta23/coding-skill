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
int mod[5] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};

struct Data { ll htor, htol, b; int m; };

template <typename T> class RMQ {
public:
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, INF) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            T vl = dat[i * 2 + 1], vr = dat[i * 2 + 2];
            dat[i] = {(vl.htor * vr.b + vr.htor) % vl.m, (vl.htol + vr.htol * vl.b) % vl.m, (vl.b * vr.b) % vl.m, vl.m};
        }
    }

    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return {0, 0, 1, dat[k].m}; // 範囲外
        else if (a <= l && r <= b) return dat[k]; // 範囲内
        else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return {(vl.htor * vr.b + vr.htor) % vl.m, (vl.htol + vr.htol * vl.b) % vl.m, (vl.b * vr.b) % vl.m, vl.m};
        }
    }
};

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    ll b = 29;

    // 左からのハッシュ化, 右からのハッシュ化, 桁数を基数を用いて表現した数, mod
    vector<RMQ<Data>> data(5, RMQ<Data>(n));
    rep(i, 5) rep(j, n) data[i].update(j, {s[j]-'a'+1, s[j]-'a'+1, b, mod[i]});

    rep(i, q){
        int tmp; cin >> tmp;
        if(tmp == 1){
            int x; char c; cin >> x >> c; x--;
            rep(i, 5) data[i].update(x, {c-'a'+1, c-'a'+1, b, mod[i]});
        }
        else if(tmp == 2){
            int l, r; cin >> l >> r; l--, r--;
            bool flag = true;
            rep(i, 5) if(data[i].query(l, r+1).htor != data[i].query(l, r+1).htol) flag = false;
            cout << (flag ? "Yes" : "No") << endl;
        }
    }
    return 0;
}