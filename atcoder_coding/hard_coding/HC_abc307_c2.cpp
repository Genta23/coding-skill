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

void stamp(vector<string>& ans, vector<string> s, int y, int x, int& cnt){
    rep(i, s.size()){
        rep(j, s[0].size()){
            if(s[i][j] == '#' && ans[y+i][x+j] != '#'){
                cnt++;
                ans[y+i][x+j] = s[i][j];
            }
        }
    }
}

bool check(vector<string>& ans, vector<string> s, int y, int x){
    rep(i, s.size()){
        rep(j, s[0].size()){
            if(ans[y+i][x+j] != s[i][j]) return false;
        }
    }
    return true;
}

int main(){
    int ha, wa; cin >> ha >> wa;
    vector<string> a(ha); rep(i, ha) cin >> a[i];
    int hb, wb; cin >> hb >> wb;
    vector<string> b(hb); rep(i, hb) cin >> b[i];
    int hx, wx; cin >> hx >> wx;
    vector<string> x(hx); rep(i, hx) cin >> x[i];

    int x_cnt = 0;
    rep(i, hx){
        rep(j, wx){
            if(x[i][j] == '#') x_cnt++;
        }
    }
    
    rep(i, 19){
        rep(j, 19){
            int cnt = 0;
            vector<string> ans(28, "............................");
            stamp(ans, a, 9, 9, cnt);
            stamp(ans, b, i, j, cnt);

            if(cnt == x_cnt){
                rep(k, 19){
                    rep(l, 19){
                        if(check(ans, x, k, l)){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}