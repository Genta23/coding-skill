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
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
bool flag[505][505];

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h); rep(i, h) cin >> s[i];

    int ii[] = {1, 0, -1, 0};
    int jj[] = {0, 1, 0, -1};

    char str[] = {'s', 'n', 'u', 'k', 'e'};
    queue<tuple<int, int, int>> que;
    que.push({0, 0, 0});
    flag[0][0] = true;
    while(!que.empty()){
        auto v = que.front();
        que.pop();
        int i = get<0>(v);
        int j = get<1>(v);
        int num = get<2>(v);
        rep(k, 4){
            if(checker(i+ii[k], j+jj[k], h, w) && !flag[i+ii[k]][j+jj[k]] && str[(num+1)%5] == s[i+ii[k]][j+jj[k]]){
                flag[i+ii[k]][j+jj[k]] = true;
                que.push({i+ii[k], j+jj[k], (num+1)%5});
            }
        }
    }
    cout << (flag[h-1][w-1] ? "Yes" : "No") << endl;
    return 0;
}