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
template<typename T> inline bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
bool flag[1000][1000];

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h); rep(i, h) cin >> s[i];

    int ii[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int jj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int cnt = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#' && !flag[i][j]){
                cnt++;
                flag[i][j] = true;
                queue<pair<int, int>> que;
                que.push({i, j});
                while(!que.empty()){
                    auto v = que.front();
                    que.pop();
                    rep(k, 8){
                        int ki = v.first + ii[k];
                        int kj = v.second + jj[k];
                        if(checker(ki, kj, h, w) && s[ki][kj] == '#' && !flag[ki][kj]){
                            que.push({ki, kj});
                            flag[ki][kj] = true;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}