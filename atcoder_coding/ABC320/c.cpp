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

int main(){
    int m; cin >> m;
    vector<string> s(3); rep(i, 3) cin >> s[i];
    
    int min = inf;
    rep(i, 10){
        vector<bool> flag(3);
        rep(j, m*3){
            int mj = j % m;
            rep(k, 3){
                if(s[k][mj]-'0' == i){
                    if(!flag[k]){
                        flag[k] = true;
                        if(flag[0] && flag[1] && flag[2]) chmin(min, j);
                        break;
                    }
                }
            }
        }
    }
    rep(i, 10){
        vector<bool> flag(3);
        rep(j, m*3){
            int mj = j % m;
            rep(k, 3){
                if(s[(k+1)%3][mj]-'0' == i){
                    if(!flag[(k+1)%3]){
                        flag[(k+1)%3] = true;
                        if(flag[0] && flag[1] && flag[2]) chmin(min, j);
                        break;
                    }
                }
            }
        }
    }
    rep(i, 10){
        vector<bool> flag(3);
        rep(j, m*3){
            int mj = j % m;
            rep(k, 3){
                if(s[(k+2)%3][mj]-'0' == i){
                    if(!flag[(k+2)%3]){
                        flag[(k+2)%3] = true;
                        if(flag[0] && flag[1] && flag[2]) chmin(min, j);
                        break;
                    }
                }
            }
        }
    }
    rep(i, 10){
        vector<bool> flag(3);
        rep(j, m*3){
            int mj = j % m;
            rep(k, 3){
                if(s[(5-k)%3][mj]-'0' == i){
                    if(!flag[(5-k)%3]){
                        flag[(5-k)%3] = true;
                        if(flag[0] && flag[1] && flag[2]) chmin(min, j);
                        break;
                    }
                }
            }
        }
    }
    rep(i, 10){
        vector<bool> flag(3);
        rep(j, m*3){
            int mj = j % m;
            rep(k, 3){
                if(s[(4-k)%3][mj]-'0' == i){
                    if(!flag[(4-k)%3]){
                        flag[(4-k)%3] = true;
                        if(flag[0] && flag[1] && flag[2]) chmin(min, j);
                        break;
                    }
                }
            }
        }
    }
    rep(i, 10){
        vector<bool> flag(3);
        rep(j, m*3){
            int mj = j % m;
            rep(k, 3){
                if(s[(3-k)%3][mj]-'0' == i){
                    if(!flag[(3-k)%3]){
                        flag[(3-k)%3] = true;
                        if(flag[0] && flag[1] && flag[2]) chmin(min, j);
                        break;
                    }
                }
            }
        }
    }
    // 順序よっては対応していないものがあったことに気づけなかった
    // 111
    // 110
    // 100
    cout << (min != inf ? min : -1) << endl;
    return 0;
}