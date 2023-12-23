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

int convertTo10(vector<int> a, int p){
    int num = 0; int r = 1;
    rep(i, a.size()){
        num += a[i]*r;
        r *= (p+1);
    }
    return num;
}

vector<int> convertFrom10(int a, int p, int k){
    vector<int> num;
    rep(i, k){
        int r = a % (p+1);
        num.push_back(r);
        a = (a-r) / (p+1);
    }
    //reverse(num.begin(), num.end());
    return num;
}

int main(){
    int n, k, p; cin >> n >> k >> p;
    vector<ll> c(n); vector<vector<int>> a(n, vector<int>(k));
    rep(i, n){
        cin >> c[i];
        rep(j, k) cin >> a[i][j];
    }

    int size = 1;
    rep(i, k) size *= (p+1);
    vector<vector<ll>> ans(n+1, vector<ll>(size, infl));
    ans[0][0] = 0;
    rep(i, n){
        rep(j, size) ans[i+1] = ans[i];
        rep(j, size){
            if(ans[i][j] == infl) continue;
            vector<int> dig = convertFrom10(j, p, k);
            rep(l, k){
                dig[l] += a[i][l];
                if(dig[l] > p) dig[l] = p;
            }
            chmin(ans[i+1][convertTo10(dig, p)], ans[i][j] + c[i]);
        }
    }

    cout << ((ans[n].back() != infl) ? ans[n].back() : -1) << endl;
    return 0;
}