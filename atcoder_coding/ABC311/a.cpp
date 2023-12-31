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
    int n; cin >> n;
    string s; cin >> s;
    bool fa = false, fb = false, fc = false;
    rep(i, n){
        if(s[i] == 'A') fa = true;
        if(s[i] == 'B') fb = true;
        if(s[i] == 'C') fc = true;

        if(fa && fb && fc){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
} 