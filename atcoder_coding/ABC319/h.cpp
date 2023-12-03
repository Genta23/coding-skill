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
    int n, q; cin >> n >> q;
    vector<pair<ll, ll>> data(n);
    for(int i=0; i<n; i++) cin >> data[i].first >> data[i].second;

    set<pair<ll, ll>, greater<ll>> start, goal;
    for(int i=0; i<n; i++){
        start.insert({data[i].first, i+1});
        goal.insert({data[i].second, i+1});
    }

    for(int i=0; i<q; i++){
        int t; cin >> t;
        if(t == 1){
            int x; ll l, r;
            cin >> x >> l >> r;
            // 既存のデータの上書きを行う
            // 削除
            start.erase(start.find({data[x-1].first, x}));
            goal.erase(goal.find({data[x-1].second, x}));
            // 追加 配列への記入
            data[x-1].first = l;
            data[x-1].second = r;
            // 追加 setへの挿入
            start.insert({l, x});
            goal.insert({r, x});

        }
        else if(t == 2){
            int x; cin >> x;
            // 要素の数を数える
            auto 
        }
    }
    return 0;
}