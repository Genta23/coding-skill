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

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    vector<int> t(q), x(q);
    vector<char> c(q);
    rep(i, q){
        int tmp1, tmp2; char tmp3; cin >> tmp1 >> tmp2 >> tmp3;
        tmp2--;
        t[i] = tmp1, x[i] = tmp2, c[i] = tmp3;
    }
    // 最後のタイミングを保存しておく
    int mem = -1;
    rep(i, q) if(t[i] != 1) mem = i;

    rep(i, q){
        if(i < mem && t[i] != 1) continue;
        if(i == mem){
            if(t[i] == 2) rep(j, n) s[j] = tolower(s[j]);
            else rep(j, n) s[j] = toupper(s[j]);
        }
        else s[x[i]] = c[i];
    }
    cout << s << endl;
    return 0;
}