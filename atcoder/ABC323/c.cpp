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
template<typename T> using max_priority_queue = priority_queue<T, vector<T>, less<T>>;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n); rep(i, m) cin >> a[i];
    vector<string> s(n); rep(i, n) cin >> s[i];
    //現状の最大値を把握することが重要

    //得点の計算を行う
    vector<int> score(n);
    vector<max_priority_queue<int>> que(n);
    int max = 0;
    rep(i, n){
        rep(j, m){
            if(s[i][j] == 'o') score[i] += a[j];
            else que[i].push(a[j]);
        }
        score[i] += i+1;
        chmax(max, score[i]);
    }

    vector<int> ans(n);
    rep(i, n){
        while(!que[i].empty()){
            if(score[i] >= max){
                break;
            }
            else{
                score[i] += que[i].top();
                que[i].pop();
                ans[i]++;
            }
        }
    }

    rep(i, n){
        cout << ans[i] << endl;
    }
    return 0;
}