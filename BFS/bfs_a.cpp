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
int shortest_path[100][100];

int main(){
    int r, c; cin >> r >> c;
    int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    vector<string> data(r); rep(i, r) cin >> data[i];

    rep(i, r) rep(j, c) shortest_path[i][j] = inf; //最短経路を保存する
    int x[] = {1, 0, -1, 0}, y[] = {0, 1, 0, -1};

    queue<pair<int, int>> que;
    que.push({sy, sx});
    shortest_path[sy][sx] = 0;

    while(!que.empty()){
        auto v = que.front();
        que.pop();
        int py = v.first, px = v.second;
        rep(k, 4){
            int ny = py + y[k], nx = px + x[k];
            if(checker(ny, nx, r, c) && data[ny][nx] == '.' && shortest_path[ny][nx] == inf){
                shortest_path[ny][nx] = shortest_path[py][px] + 1;
                que.push({ny, nx});
            }
        }
    }
    cout << shortest_path[gy][gx] << endl;
    return 0;
}