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
    vector<int> d(n);
    rep(i, n) cin >> d[i];

    int cnt = 0;
    for(int i=1; i<=n; i++){
        string si = to_string(i);
        //sort(si.begin(), si.end());
        //si.erase(unique(si.begin(), si.end()), si.end());
        for(int j=1; j<=d[i-1]; j++){
            string s;
            string sj = to_string(j);
            s = si + sj;
            sort(s.begin(), s.end());
            s.erase(unique(s.begin(), s.end()), s.end());
            if(s.size() == 1){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}