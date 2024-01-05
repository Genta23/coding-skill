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
bool flag[503][503];

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h); rep(i, h) cin >> c[i];

    int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
    pair<int, int> s, g;
    rep(i, h){
        rep(j, w){
            if(c[i][j] == 's') s.first = i, s.second = j;
            if(c[i][j] == 'g') g.first = i, g.second = j;
        }
    }

    stack<pair<int, int>> st;
    flag[s.first][s.second] = true;
    st.push({s.first, s.second});
    while(!st.empty()){
        auto v = st.top();
        st.pop();
        int y = v.first, x = v.second;
        rep(k, 4){
            int ny = y + dy[k], nx = x + dx[k];
            if(checker(ny, nx, h, w) && c[ny][nx] != '#' && !flag[ny][nx]){
                flag[ny][nx] = true;
                st.push({ny, nx});
            }
        }
    }

    cout << (flag[g.first][g.second] ? "Yes" : "No") << endl;
    return 0;
}