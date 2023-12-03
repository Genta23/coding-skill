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
    /*int n = 10;
    vector<string> s(n);
    vector<int> d(n);
    rep(i, n) cin >> s[i] >> d[i];
    rep(i, n) cout << "if(s==\"" << s[i] << "\") cout << " << d[i] << " << endl;" << endl;*/

    string s; cin >> s;
    if(s=="tourist") cout << 3858 << endl;
    if(s=="ksun48") cout << 3679 << endl;
    if(s=="Benq") cout << 3658 << endl;
    if(s=="Um_nik") cout << 3648 << endl;
    if(s=="apiad") cout << 3638 << endl;
    if(s=="Stonefeang") cout << 3630 << endl;
    if(s=="ecnerwala") cout << 3613 << endl;
    if(s=="mnbvmar") cout << 3555 << endl;
    if(s=="newbiedmy") cout << 3516 << endl;
    if(s=="semiexp") cout << 3481 << endl;
    return 0;
}