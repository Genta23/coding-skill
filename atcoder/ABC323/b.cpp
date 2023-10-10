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
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<int> ans(n);
    rep(i, n){
        int score = 0;
        rep(j, n){
            if(s[i][j] == 'o') score++;
        }
        ans[i] = score;
    }

    for(int i = n-1; i>=0; i--){
        rep(j, n){
            if(ans[j] == i) cout << j+1 << " ";
        }
    }
    cout << endl;
    return 0;
}