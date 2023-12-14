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
    // オリジナル
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    set<int> front_st, back_st;
    rep(i, n-m+1){
        bool flag = true;
        rep(j, m){
            if(s[i+j] != t[j]) flag = false;
        }
        if(flag){
            rep(j, m) s[i+j] = '#';
            front_st.insert(i);
            back_st.insert(n-1 - i - (m-1));
            //cout << i << " " << n-1 - i << endl;
        }
    }

    rep(i, n-m+1){
        if(front_st.find(i) != front_st.end()){
            rep(j, m) s[i+j] = '#';
            for(int j=1; j<m; j++){
                bool flag = false;
                rep(k, m) if(i+k+j < n && (s[i+j+k] != '#')) flag = true;
                rep(k, m){
                    if(i+k+j < n && (s[i+j+k] == '#' || s[i+j+k] == t[k])) continue;
                    else flag = false;
                }
                if(flag) front_st.insert(i+j);
            }
        }
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    rep(i, n-m+1){
        if(back_st.find(i) != back_st.end()){
            rep(j, m) s[i+j] = '#';
            for(int j=1; j<m; j++){
                bool flag = false;
                rep(k, m) if(i+k+j < n && (s[i+j+k] != '#')) flag = true;
                rep(k, m){
                    if(i+j+k < n && (s[i+j+k] == '#' || s[i+j+k] == t[k])) continue;
                    else flag = false;
                }
                if(flag) back_st.insert(i+j);
            }
        }
    }

    /*rep(i, n) cout << s[i];
    cout << endl;*/

    rep(i, n){
        if(s[i] != '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}