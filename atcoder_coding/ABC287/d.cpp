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
#include <iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    string s, t; cin >> s >> t;

    // 前から観察した時
    string a, b;
    b = s.substr(s.size()-1 - (t.size()-1));

    vector<int> flag(t.size()+1);

    bool flag_front = true;
    rep(i, t.size()){
        if(b[i] == t[i]) ;
        else if(b[i] == '?') ;
        else if(t[i] == '?') ;
        else flag_front = false;
    }
    if(flag_front){
        flag[0] = true;
        rep(i, t.size()){
            if(s[i] == t[i] || s[i] == '?' || t[i] == '?') flag[1+i] = true;
            else break;
        }
    }
    
    bool flag_back = true;
    rep(i, t.size()){
        if(s[i] == t[i]) ;
        else if(s[i] == '?') ;
        else if(t[i] == '?') ;
        else flag_back = false; // ここのミス
    }
    if(flag_back){
        flag[t.size()] = true;
        rep(i, t.size()){
            if(s[s.size()-1 - i] == t[t.size()-1 - i] || s[s.size()-1 - i] == '?' || t[t.size()-1 - i] == '?') flag[t.size()-1 - i] = true;
            else break;
        }
    }

    rep(i, t.size()+1){
        cout << (flag[i] ? "Yes" : "No") << endl;
    }
    return 0;
}