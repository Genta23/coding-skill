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
char ans[5][5];

int main(){
    int n; cin >> n;
    string r, c; cin >> r >> c;

    vector<int> rr, cc;
    rep(i, n){
        if(r[i] == 'A') rr.push_back(1);
        if(r[i] == 'B') rr.push_back(2);
        if(r[i] == 'C') rr.push_back(3);
    }
    rep(i, n){
        if(c[i] == 'A') cc.push_back(1);
        if(c[i] == 'B') cc.push_back(2);
        if(c[i] == 'C') cc.push_back(3);
    }

    map<char, int> mr, mc;
    rep(i, n){
        mr[r[i]] = i;
    }
    rep(i, n){
        mc[c[i]] = i;
    }
    if(mr.size() != 3) return 0;
    if(mc.size() != 3) return 0;

    bool flag = false;
    if(r[0] == c[0]) flag = true;

    vector<vector<int>> ans(n, vector<int>(n));
    if(flag){
        vector<int> c_flag(3), r_flag(3);
        rep(i, n){
            if(!c_flag[cc[i]-1]){
                c_flag[cc[i]-1] = true;
                ans[0][i] = cc[i];
            }
        }
        rep(i, n){
            if(!r_flag[rr[i]-1]){
                r_flag[rr[i]-1] = true;
                ans[i][0] = rr[i];
            }
        }

        vector<int> ori{0, 1, 2, 3, 0};
        vector<vector<int>> data;
        rep(i, n-1){
            data.push_back(ori);
        }
        rep(i, n-1){
            data[i+1].erase(data[i+1].begin() + ans[i+1][0]);
        }
    }

    rep(i, n){
        rep(j, n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    //vector<vector<int>> ans(n, vector<int>(n));
    // 1行目を作成する
    
}