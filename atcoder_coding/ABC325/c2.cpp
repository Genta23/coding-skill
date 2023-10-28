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
    vector<string> data(h); rep(i, h) cin >> data[i];

    ll cnt = 0;
    rep(i, h){
        rep(j, w){
            if(data[i][j] == '#') cnt++;
        }
    }
    cout << cnt << endl;

    rep(i, h){
        rep(j, w){
            if(data[i][j] == '#'){
                flag[i][j] = true;
                if(j+1 < w && data[i][j+1] == '#' && !flag[i][j+1]){
                    cnt--; flag[i][j+1] = true;
                }
                if(i+1 < h && j+1 < w && data[i+1][j+1] == '#' && !flag[i+1][j+1]){
                    cnt--; flag[i+1][j+1] = true;
                }
                if(i+1 < h && data[i+1][j] == '#' && !flag[i+1][j]){
                    cnt--; flag[i+1][j] = true;
                }
                if(i+1 < h && j > 0 && data[i+1][j-1] == '#' && !flag[i+1][j-1]){
                    cnt--; flag[i+1][j-1] = true;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}