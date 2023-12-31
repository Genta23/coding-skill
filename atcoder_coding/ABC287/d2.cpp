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
    string s, t; cin >> s >> t;
    vector<bool> pre(t.size()+1), suf(t.size()+1);

    // pre : sの先頭i文字に関して
    pre[0] = true;
    rep(i, t.size()){
        if(s[i] == t[i] || s[i] == '?' || t[i] == '?') pre[i+1] = true;
        else break;
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    // suf : sの末尾 t.size() - i文字に関して
    suf[0] = true;
    rep(i, t.size()){
        if(s[i] == t[i] || s[i] == '?' || t[i] == '?') suf[i+1] = true;
        else break;
    }

    reverse(suf.begin(), suf.end());

    rep(i, t.size()+1){
        if(pre[i] && suf[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}