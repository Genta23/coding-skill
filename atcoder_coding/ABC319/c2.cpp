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
    int n = 3;
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, n) rep(j, 3) cin >> c[i][j];

    // 9!だから全探索では?? だからなんか3なんだわ これ4なら上手くいかないもん
    // 0 - 8を扱って 判定はsetとvectorの長さを比較すればいい
    vector<int> a(9);
    rep(i, 9) a[i] = i;
    sort(a.begin(), a.end());

    // 縦1, 2, 3 横4, 5, 6 斜め7, 8

    int cnt = 0;
    do{
        vector<vector<int>> vec(8);
        vector<set<int>> st(8);
        bool flag = true;

        rep(i, n){
            int y = a[i] / n;
            int x = a[i] % n;

            if(x == 0){
                vec[0].push_back(c[y][x]);
                st[0].insert(c[y][x]);
            }
            else if(x == 1){
                vec[1].push_back(c[y][x]);
                st[1].insert(c[y][x]);
            }
            else if(x == 2){
                vec[2].push_back(c[y][x]);
                st[2].insert(c[y][x]);
            }

            if(y == 0){
                vec[3].push_back(c[y][x]);
                st[3].insert(c[y][x]);
            }
            else if(y == 1){
                vec[4].push_back(c[y][x]);
                st[4].insert(c[y][x]);
            }
            else if(y == 2){
                vec[5].push_back(c[y][x]);
                st[5].insert(c[y][x]);
            }

            if(x == y){
                vec[6].push_back(c[y][x]);
                st[6].insert(c[y][x]);
            }
            if(x == 2-y){ // 負の数の%の挙動が予想外
                vec[7].push_back(c[y][x]);
                st[7].insert(c[y][x]);
            }

            rep(i, 8){
                if(vec[i].size() == 2){
                    if(st[i].size() == 1) flag = false;
                }
            }
        }

        if(flag) cnt++;
    }while(next_permutation(a.begin(), a.end()));
    cout << cnt << endl;

    int r = 1;
    rep(i, 9){
        r *= (i+1);
    }
    cout << r << endl;

    double ans = cnt / (double)r;
    cout << ans << endl;

    return 0;
}