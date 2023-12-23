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
#include <iomanip>
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
    // 0 - 8を扱って 判定はsetとvectorの長さを比較すればいい -> setは時間がかかるので、vectorの最初の2要素で判定
    vector<int> a(9);
    rep(i, 9) a[i] = i;
    sort(a.begin(), a.end());

    // 縦1, 2, 3 横4, 5, 6 斜め7, 8

    int cnt = 0;
    do{
        vector<vector<int>> vec(8);
        rep(i, 9){
            int y = a[i] / n;
            int x = a[i] % n;

            vec[x].push_back(c[y][x]);
            vec[3+y].push_back(c[y][x]);

            // 負の数の%の挙動が予想外
            if(x == y) vec[6].push_back(c[y][x]);
            if(x == 2-y) vec[7].push_back(c[y][x]);
        }

        bool flag = true;
        rep(i, 8) if(vec[i][0] == vec[i][1]) flag = false;
        if(flag) cnt++;

    }while(next_permutation(a.begin(), a.end()));

    int r = 1;
    rep(i, 9) r *= (i+1);

    cout << fixed << setprecision(12) << cnt/(double)r << endl;
    return 0;
}