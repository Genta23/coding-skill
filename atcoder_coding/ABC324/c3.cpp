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
    int n; cin >> n;
    string t; cin >> t;
    vector<string> s(n); rep(i, n) cin >> s[i];
    int t__ = t.size();
    vector<int> ans;
    rep(i, n){
        int s__ = s[i].size();
        if(s__ == t__){
            if(s[i] == t) ans.push_back(i+1);
            else{
                int cnt = 0;
                rep(j, t__){
                    if(s[i][j] != t[j]) break;
                    cnt++;
                }
                rep(j, t__){
                    if(s[i][s__-1 - j] != t[t__-1 - j]) break;
                    cnt++;
                }
                if(cnt == t__ - 1) ans.push_back(i+1);
            }
        }
        else if(abs(s__ - t__) == 1){
            int ___ = min(s__, t__);
            int cnt = 0;
            rep(j, ___){
                if(cnt == ___) break;
                if(s[i][j] != t[j]) break;
                cnt++;
            }
            rep(j, ___){
                if(cnt == ___) break;
                if(s[i][s__-1 - j] != t[t__-1 - j]) break;
                cnt++;
            }
            if(cnt == ___) ans.push_back(i+1);
        }
        else{
            ;
        }
    }
    int a__ = ans.size();
    cout << a__ << endl;
    rep(i, a__){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}