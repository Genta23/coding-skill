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
bool flag[1000][1000];

int main(){
    int h, w; cin >> h >> w;
    vector<string> data(h);
    rep(i, h) cin >> data[i];

    int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    //cout << "test" << endl;
    queue<pair<int, int>> que;
    ll cnt = 0;
    rep(i, h){
        rep(j, w){
            if(data[i][j] == '#' && !flag[i][j]){ 
                flag[i][j] = true;
                //cout << "pule" << i << j << endl;
                cnt++;
                que.push({i, j});
                while(!que.empty()){
                    //cout << "rup" << endl;
                    auto v = que.front();
                    que.pop();
                    //flag[v.first][v.second] = true;
                    //cout <<"test" << v.first << v.second << endl;
                    rep(k, 8){
                        int tx = v.first + x[k];
                        int ty = v.second + y[k];
                        if(tx >= 0 && tx < h && ty >= 0 && ty < w && data[tx][ty] == '#' && !flag[tx][ty]){
                            que.push({tx, ty});
                            flag[tx][ty] = true;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}