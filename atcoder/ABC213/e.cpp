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
    vector<string> s(h);
    rep(i, h) cin >> s[i]; //ここがiではなくhになっていた

    int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
    
    int ans[505][505];
    bool vis[505][505] = {};
    rep(i, h) rep(j, w) ans[i][j] = inf;

    min_priority_queue<pair<int, int>> que;
    que.push({0, 0});
    ans[0][0] = 0;

    //なぜ座標のみのpairになっていないのか
    //優先度が重要 何に対する優先度かという部分だけど、これはそれまでの経路の長さと考えることができる
    //従って、解答の例では経路の座標、一次元での場所という形になっていた
    //以上の問題より、e2に完成版を記す

    while(!que.empty()){
        auto v = que.top(); que.pop();
        int pos_i = v.first, pos_j = v.second;

        if(vis[pos_i][pos_j]) continue;
        vis[pos_i][pos_j] =  true;

        rep(i, 4){
            int pos_nxt_i = pos_i + y[i], pos_nxt_j = pos_j + x[i];
            if(pos_nxt_i >= 0 && pos_nxt_i < h && pos_nxt_j >= 0 && pos_nxt_j < w){//範囲条件
                if(s[pos_nxt_i][pos_nxt_j] == '.'){//この条件が通らない
                    if(chmin(ans[pos_nxt_i][pos_nxt_j], ans[pos_i][pos_j])) que.push({pos_nxt_i, pos_nxt_j});
                }
            }
        }

        for(int i=pos_i-2; i<=pos_i+2; i++){
            for(int j=pos_j-2; j<=pos_j+2; j++){
                if(abs(pos_i - i) + abs(pos_j - j) == 4) continue;
                if(i >= 0 && i < h && j >= 0 && j < w){
                    if(chmin(ans[i][j], ans[pos_i][pos_j] + 1)) que.push({i, j});
                }
            }
        }
    }
    cout << ans[h-1][w-1] << endl;
    return 0;
}