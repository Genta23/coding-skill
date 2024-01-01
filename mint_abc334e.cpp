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
#include "atcoder/modint.hpp" // #include "atcoder/modint.hpp" でも通る 理想は<atcoder/modint.hpp>だが
using namespace std;
using namespace atcoder;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
using mint = modint998244353;

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h); rep(i, h) cin >> s[i];

    vector<vector<int>> data(h, vector<int>(w));
    int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

    int cnt = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#' && data[i][j] == 0){
                cnt++;
                queue<pair<int, int>> que;
                que.push({i, j});
                data[i][j] = cnt;
                while(!que.empty()){
                    auto v = que.front(); que.pop();
                    rep(k, 4){
                        if(checker(v.first+dy[k], v.second+dx[k], h, w) && s[v.first+dy[k]][v.second+dx[k]] == '#' && data[v.first+dy[k]][v.second+dx[k]] == 0){
                            que.push({v.first+dy[k], v.second+dx[k]});
                            data[v.first+dy[k]][v.second+dx[k]] = cnt;
                        }
                    }
                }
            }
        }
    }
    //cout << cnt << endl;

    int r_cnt = 0;
    mint sum = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '.'){
                r_cnt++;
                set<int> st;
                rep(k, 4){
                    if(checker(i+dy[k], j+dx[k], h, w)){
                        if(data[i+dy[k]][j+dx[k]] > 0){
                            st.insert(data[i+dy[k]][j+dx[k]]);
                        }
                    }
                }
                if(st.size() == 0) sum += (ll)(cnt + 1); // sizeが0のときは成分1増える
                else sum += (ll)(cnt - st.size() + 1);
            }
        }
    }
    cout << (sum/r_cnt).val() << endl;
    return 0;
}