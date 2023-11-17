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
    int n; cin >> n;
    vector<vector<int>> data(n); //このミスが多いような気がする。
    rep(i, n){
        int c; cin >> c;
        rep(j, c){
            int a; cin >> a;
            data[i].push_back(a);
        }
    }
    int x; cin >> x;
    vector<pair<int, int>> ans;
    rep(i, n){
        rep(j, data[i].size()){
            if(x == data[i][j]) ans.push_back({data[i].size(), i});
        }
    }
    sort(ans.begin(), ans.end());
    vector<int> last_ans;
    rep(i, ans.size()){
        if(ans[0].first == ans[i].first) last_ans.push_back(ans[i].second);
    }
    cout << last_ans.size() << endl;
    rep(i, last_ans.size()){
        cout << last_ans[i]+1 << " ";
    }
    cout << endl;
    return 0;
}
