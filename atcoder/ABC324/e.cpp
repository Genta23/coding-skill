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
    string t; cin >> t;
    vector<string> s(n); rep(i, n) cin >> s[i];

    vector<pair<int, int>> data(n);
    //順に依存しないことからfront, back両方ソートして、二分探索を使用する
    vector<int> front, back;
    rep(i, n){
        int s__ = s[i].size(), t__ = t.size();

        int cnt_front = 0;
        rep(j, s__) if(s[i][j] == t[cnt_front]) cnt_front++;

        int cnt_back = 0;
        rep(j, s__) if(s[i][s__-1 - j] == t[t__-1 - cnt_back]) cnt_back++;

        front.push_back(cnt_front);
        back.push_back(cnt_back);
    }
    sort(front.begin(), front.end());
    sort(back.begin(), back.end());

    ll ans = 0;
    rep(i, n){
        int rest = t.size() - front[i];

        auto itr = lower_bound(back.begin(), back.end(), rest);
        int d = distance(back.begin(), itr); 

        ans += (n - d);
    }
    cout << ans << endl;
    return 0;
}