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
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
        }
    }

    int cnt = 0;
    rep(i, 3){
        set<int> st;
        rep(j, 3){
            st.insert(c[i][j]);
        }
        if(st.size() == 2) cnt++;
    }
    rep(i, 3){
        set<int> st;
        rep(j, 3){
            st.insert(c[j][i]);
        }
        if(st.size() == 2) cnt++;
    }
    rep(i, 1){
        set<int> st;
        rep(j, 3){
            st.insert(c[j][j]);
        }
        if(st.size() == 2) cnt++;
    }
    rep(i, 1){
        set<int> st;
        rep(j, 3){
            st.insert(c[j][2-j]);
        }
        if(st.size() == 2) cnt++;
    }
    //cout << cnt << endl;

    double p = 1;
    rep(i, cnt){
        p = 2.0*p/3.0;
    }
    cout << p << endl;
    return 0;
}