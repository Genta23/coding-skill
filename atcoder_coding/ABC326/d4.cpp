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

bool check(vector<string>& ans, string& c, int n){
    string str = "ABC";
    while(str.size() < n) str += '.';
    sort(str.begin(), str.end());
    rep(i, n){
        string col = "";
        char c_check;
        for(int j=n-1; j>=0; j--){
            col += ans[j][i];
            if(ans[j][i] != '.') c_check = ans[j][i];
        }
        sort(col.begin(), col.end());
        if(col != str) return false;
        if(c_check != c[i]) return false;
    }
    return true;
}
int main(){
    int n; cin >> n;
    string r, c; cin >> r >> c;
    
    string str = "ABC";
    while(str.size() < n) str += '.';
    sort(str.begin(), str.end());

    vector<vector<string>> row(3);
    do{
        char tmp = '.';
        for(auto x : str){
            if(x != '.'){
                tmp = x;
                break;
            }
        }
        row[tmp - 'A'].push_back(str);
    }while(next_permutation(str.begin(), str.end()));

    int p = n*(n-1)*(n-2)/3;
    int max = 1;
    rep(i, n) max *= p;
    
    int cnt = 0;
    while(cnt < max){
        vector<int> dig(n);
        int tmp = cnt;
        rep(i, n){
            dig[i] = tmp % p;
            tmp /= p;
        }

        vector<string> ans(n);
        rep(i, n) ans[i] = row[r[i] - 'A'][dig[i]];

        if(check(ans, c, n)){
            cout << "Yes" << endl;
            rep(i, n) cout << ans[i] << endl;
            return 0;
        }
        cnt++;
    }

    cout << "No" << endl;
    return 0;
}