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
#include <functional>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    vector<pair<string, int>> s(n); //たまにやるサイズ入力を忘れるやつ
    rep(i, n){
        string tmp; cin >> tmp;
        s[i] = {tmp, i};
    }

    sort(s.begin(), s.end());

    vector<int> ans(n);
    rep(i, n-1){
        if(i < n-1){ // 後ろと比較
            int cnt = 0;
            rep(j, s[i].first.size()){
                if(s[i].first[j] == s[i+1].first[j]) cnt++;
                else break;
            }
            chmax(ans[s[i].second], cnt);
            chmax(ans[s[i+1].second], cnt);
        }
    }

    rep(i, n) cout << ans[i] << endl;
    return 0;
}