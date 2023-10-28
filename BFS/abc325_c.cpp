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
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
bool flag[1007][1007];

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h); rep(i, h) cin >> s[i];
    
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}, dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

    int cnt = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#' && !flag[i][j]){
                cnt++;
                queue<pair<int, int>> que;
                flag[i][j] = true;
                que.push({i, j});
                while(!que.empty()){
                    auto v = que.front();
                    que.pop();
                    int cy = v.first, cx = v.second;
                    rep(k, 8){
                        int ny = cy + dy[k], nx = cx + dx[k];
                        if(checker(ny, nx, h, w) && s[ny][nx] == '#' && !flag[ny][nx]){
                            flag[ny][nx] = true;
                            que.push({ny, nx});
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}