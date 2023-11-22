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
    string s; cin >> s;
    int max = 0;
    rep(i, s.size()){
        int cnt1 = -1;
        rep(j, s.size()){
            if(i+j > s.size()) break;
            if(i-j < 0) break;
            if(s[i+j] == s[i-j]){
                cnt1 += 2;
            }
            else break;
        }
        chmax(max, cnt1);
        int cnt2 = 0;
        rep(j, s.size()){
            if(i+1+j > s.size()) break;
            if(i-j < 0) break;
            if(s[i+1+j] == s[i-j]){
                cnt2 += 2;
            }
            else break;
        }
        chmax(max, cnt2);
    }
    cout << max << endl;
    return 0;
}