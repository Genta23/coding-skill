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
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    int h, w; cin >> h >> w;
    vector<string> s;
    rep(i, h){
        string temp; cin >> temp;
        s.push_back(temp);
    }

    vector<pair<int, int>> ans;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == 'o'){
                ans.push_back({i, j});
            }
        }
    }

    /*rep(i, ans.size()){
        cout << ans[i].first << "  " << ans[i].second << endl;
    }*/

    cout << abs(ans[0].first-ans[1].first) +  abs(ans[0].second-ans[1].second) << endl;
    return 0;
}