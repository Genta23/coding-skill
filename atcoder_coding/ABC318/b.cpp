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
bool flag[107][107];

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    rep(i, n){
        for(int j=a[i]; j<b[i]; j++){
            for(int k=c[i]; k<d[i]; k++){
                flag[j][k] = true;
            }
        }
    }

    int ans = 0;
    rep(i, 107){
        rep(j, 107){
            if(flag[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}