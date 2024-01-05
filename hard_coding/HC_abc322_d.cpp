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
const int n = 4;

vector<string> rotate(vector<string> s){
    vector<string> tmp(n);
    rep(i, n){
        rep(j, n){
            tmp[i] += s[n-1 - j][i];
        }
    }
    return tmp;
}

bool stamp(vector<string>& ans, vector<string> s, int y, int x){
    rep(i, n){
        rep(j, n){
            if(ans[y+i][x+j] == '#' && s[i][j] == '#') return false;
            if(s[i][j] == '#') ans[y+i][x+j] = s[i][j];
        }
    }
    return true;
}

pair<int, int> point(vector<string>& ans){
    rep(i, 13){
        rep(j, 13){
            if(ans[i][j] == '#'){
                return {i, j};
            }
        }
    }
    return {0, 0};
}

bool check(vector<string>& ans, int y, int x){
    rep(i, n){
        rep(j, n){
            if(ans[y+i][x+j] != '#') return false;
        }
    }
    return true;
}

int main(){
    vector<string> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    int cnt = 0;
    rep(i, n) rep(j, n) if(a[i][j] == '#') cnt++;
    rep(i, n) rep(j, n) if(b[i][j] == '#') cnt++;
    rep(i, n) rep(j, n) if(c[i][j] == '#') cnt++;

    if(cnt != 16){
        cout << "No" << endl;
        return 0;
    }

    for(int i=1; i<=n*n; i++){ // aの盤面を中心とする 中心の4*4以外ゴミ溜まってようが知らん
        // 軸となる盤面作成
        rep(j, 13){
            rep(k, 13){
                rep(l, 13){
                    rep(m, 13){
                        vector<string> ans(16, "................");
                        stamp(ans, a, 6, 6);
                        if(!stamp(ans, b, j, k)) continue;
                        if(!stamp(ans, c, l, m)) continue;
                        auto v = point(ans);
                        if(check(ans, v.first, v.second)){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        if(i%n == 0) b = rotate(b); //戻り値受けてなかった...
        c = rotate(c);
    }
    cout << "No" << endl;
    return 0;
}