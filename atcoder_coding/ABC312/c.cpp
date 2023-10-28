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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m); rep(i, n) cin >> a[i]; rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    min_priority_queue<int> ans;

    rep(i, n){
        auto ita = upper_bound(a.begin(), a.end(), a[i]); ita--;
        int da = distance(a.begin(), ita);

        auto itb = lower_bound(b.begin(), b.end(), a[i]);
        int db = distance(b.begin(), itb);

        if(da+1 >= m-db) ans.push(a[i]);
    }

    rep(i, m){
        auto ita = upper_bound(a.begin(), a.end(), b[i]+1); ita--;
        int da = distance(a.begin(), ita);

        auto itb = lower_bound(b.begin(), b.end(), b[i]+1);
        int db = distance(b.begin(), itb);

        if(da+1 >= m-db) ans.push(b[i]+1);
    }
    
    cout << ans.top() << endl;

    return 0;
}