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
#include "atcoder/modint.hpp" // #include "atcoder/modint.hpp" でも通る 理想は<atcoder/modint.hpp>だが
using namespace std;
using namespace atcoder;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
using mint = modint;

mint Hs(string s, vector<mint>& b){
    mint val = 0;
    rep(i, s.size()){
        val += (s[i]-'a'+1)*b[i];
    }
    return val;
}

mint HsSlide(mint v, string& s, int l, int r, vector<mint>& b){
    v *= b[b.size()-2];
    v -= ((s[l]-'a'+1)*b[0]*b[b.size()-2]);
    v += (s[r]-'a'+1);
    return v;
}

mint HsChange(mint v, string& s, int i, vector<mint>& b){
    v += (s[i]-'a'+1)*b[i];
    v -= (s[(int)b.size()+i]-'a'+1)*b[i];
    return v;
}

int main(){
    int n; cin >> n;
    string t; cin >> t;
    const int m1 = 10000007, m2 = 100000007;
    int b = 31;

    mint::set_mod(m1);
    vector<mint> b1(n), b1_rev(n);
    mint r = 1;
    rep(i, n){
        b1[i] = r;
        b1_rev[i] = r;
        r *= b;
    }
    reverse(b1.begin(), b1.end()); // n, n-1,...,1

    vector<mint> v1(n+1);
    v1[0] = Hs(t.substr(0, n), b1);
    rep(i, n) v1[i+1] = HsSlide(v1[i], t, i, n+i, b1);

    vector<mint> vr1(n+1);
    vr1[0] = Hs(t.substr(n, n), b1_rev);
    rep(i, n) vr1[i+1] = HsChange(vr1[i], t, i, b1_rev);


   
    mint::set_mod(m2);
    vector<mint> b2(n), b2_rev(n);
    r = 1;
    rep(i, n){
        b2[i] = r;
        b2_rev[i] = r;
        r *= b;
    }
    reverse(b2.begin(), b2.end()); // n, n-1,...,1

    vector<mint> v2(n+1);
    v2[0] = Hs(t.substr(0, n), b2);
    rep(i, n) v2[i+1] = HsSlide(v2[i], t, i, n+i, b2);

    vector<mint> vr2(n+1);
    vr2[0] = Hs(t.substr(n, n), b2_rev);
    rep(i, n) vr2[i+1] = HsChange(vr2[i], t, i, b2_rev);

    rep(i, n+1){
        if(v1[i] == vr1[i] && v2[i] == vr2[i]){
            string ans = t.substr(i, n);
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}