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

void swap_row(vector<string>& data, int a, int b){
    string tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

void swap_column(vector<string>& data, int a, int b){
    string tmp = "";
    rep(i, data.size()) tmp += data[i][a];
    rep(i, data.size()) data[i][a] = data[i][b];
    rep(i, data.size()) data[i][b] = tmp[i];
}

int main(){
    int h, w; cin >> h >> w;
    vector<string> data(h); rep(i, h) cin >> data[i];

    vector<vector<int>> row(h, vector<int>(26));
    vector<vector<int>> column(w, vector<int>(26));

    vector<bool> hf(h), wf(w);

    rep(i, h){
        rep(j, w){
            row[i][data[i][j] - 'a']++;
            column[j][data[i][j] - 'a']++;
        }
    }

    int hc = h, wc = w;
    rep(_, h+w){
        // 消せる列の探索
        vector<pair<int, int>> hp, wp;
        rep(i, h){
            if(hf[i]) continue;
            rep(j, 26){
                if(row[i][j] == wc && row[i][j] >= 2){
                    hp.push_back({i, j});
                }
            }
        }
        rep(i, w){
            if(wf[i]) continue;
            rep(j, 26){
                if(column[i][j] == hc && column[i][j] >= 2){
                    wp.push_back({i, j});
                }
            }
        }
        
        // 削除と整理
        for(auto x : hp){
            hf[x.first] = true;
            rep(i, w) column[i][x.second]--;
            hc--;
        }
        for(auto x : wp){
            wf[x.first] = true;
            rep(i, h) row[i][x.second]--;
            wc--;
        }
    }
    cout << hc * wc << endl;
    return 0;
}