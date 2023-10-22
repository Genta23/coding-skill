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
const int NUM = 998244353;

int main(){
    int n; cin >> n;
    vector<int> data(n);
    vector<bool> flag(n);
    int fc = 1;

    min_priority_queue<int> que;

    data[0] = n;
    flag[0] = true;
    ll ans = 0;
    que.push(0);
    while(1){
        int v = que.top();
        que.pop();
        int div = data[v]/2, rest = data[v]%2;

        if(data[v]%2 == 0){
            flag[v] = false;
            fc--;
        }
        data[v] -= 2*div;
        ans += div; //勝負を行った回数
        ans %= NUM;

        //flagの更新
        if(!flag[v+1]) fc++;
        if(!flag[0]) fc++;
        flag[v+1] = true;
        flag[0] = true;

        data[v+1] += div;
        data[0] += div;

        if(data[v+1] > 1){
            que.push(v+1);
        }

        if(data[0] > 1){
            que.push(0);
        }
        cout << fc << endl;
        if(fc == n){
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}