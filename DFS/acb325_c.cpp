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
bool flag[1007][1007];
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}, dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(vector<string> &s, int y, int x, int h, int w){
    rep(i, 8){
        int ny = y + dy[i], nx = x + dx[i];
        if(checker(ny, nx, h, w) && !flag[ny][nx] && s[ny][nx] == '#'){
            flag[ny][nx] = true;
            dfs(s, ny, nx, h, w);
        }
    }
}

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h); rep(i, h) cin >> s[i];

    int cnt = 0;
    rep(i, h) rep(j, w) if(!flag[i][j] && s[i][j] == '#'){ cnt++; flag[i][j] = true; dfs(s, i, j, h, w); }
    
    cout << cnt << endl;
    return 0;
}