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
int dis[2007][2007];
char mp[2007][2007];
int main(){
    int h, w; cin >> h >> w;
    vector<string> data(h); rep(i, h) cin >> data[i];

    pair<int, int> start, goal;
    string s = ">v<^";
    int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

    rep(i, h) rep(j, w) mp[i][j] = '.';

    rep(i, h){
        rep(j, w){
            if(data[i][j] == 'S') start = {i, j};
            if(data[i][j] == 'G') goal = {i, j};
            if(data[i][j] == '#') mp[i][j] = '#';
            rep(k, 4){
                if(data[i][j] == s[k]){
                    mp[i][j] = '#';
                    int y = i, x = j;
                    while(1){
                        y += dy[k], x += dx[k];
                        if(checker(y, x, h, w) && data[y][x] == '.'){
                            mp[y][x] = '#';
                        }
                        else break;
                    }
                }
            }
        }
    }

    rep(i, h) rep(j, w) dis[i][j] = -1;

    queue<pair<int, int>> que;
    dis[start.first][start.second] = 0;
    que.push(start);
    while(!que.empty()){
        auto v = que.front(); que.pop();
        rep(i, 4){
            int y = v.first + dy[i];
            int x = v.second + dx[i];
            if(checker(y, x, h, w) && dis[y][x] == -1 && mp[y][x] == '.'){
                dis[y][x] = dis[v.first][v.second] + 1;
                que.push({y, x});
            }
        }
    }

    cout << dis[goal.first][goal.second] << endl;
    return 0;
}