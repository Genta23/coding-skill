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
bool flag_cnt[200][200];
bool flag_check[200][200];
int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n); rep(i, n) cin >> s[i];
    queue<pair<int, int>> que;
    que.push({1, 1});
    flag_cnt[1][1] = true;
    flag_check[1][1] = true;
    int ii[4] = {1, 0, -1 , 0}, jj[4] = {0, 1, 0, -1};
    ll ans = 1;
    while(!que.empty()){
        auto v = que.front();
        que.pop();
        rep(i, 4){
            int ti = v.first, tj = v.second;
            while(s[ti][tj] == '.'){
                if(!flag_cnt[ti][tj]){
                    flag_cnt[ti][tj] = true;
                    ans++;
                }
                ti += ii[i], tj += jj[i];
            }
            //更新が一回多いので戻す
            ti -= ii[i], tj -= jj[i];
            if(!flag_check[ti][tj]){
                flag_check[ti][tj] = true;
                que.push({ti, tj});
            }
            /*rep(i, n){
                rep(j, m){
                    cout << flag_cnt[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;*/
        }
    }
    cout << ans << endl;
    return 0;
}