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
bool pass_flag[203][203];
bool st_flag[203][203];

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n); rep(i, n) cin >> s[i];

    int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

    queue<pair<int, int>> que;
    que.push({1, 1});
    pass_flag[1][1] = true, st_flag[1][1] = true;
    int ans = 1;
    while(!que.empty()){
        auto v = que.front(); que.pop();
        rep(i, 4){
            int ny = v.first, nx = v.second;
            while(1){
                ny += dy[i], nx += dx[i];
                if(s[ny][nx] == '#') break;
                if(!pass_flag[ny][nx]){
                    pass_flag[ny][nx] = true;
                    ans++;
                }
            }
            ny -= dy[i], nx -= dx[i]; //更新を戻す
            if(!st_flag[ny][nx]){
                st_flag[ny][nx] = true;
                que.push({ny, nx});
            }
        }
    }
    cout << ans << endl;
    return 0;
}