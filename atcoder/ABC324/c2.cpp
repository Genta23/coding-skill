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

int main(){
    int n; cin >> n;
    string td; cin >> td;
    vector<pair<string, int>> s(n); 
    rep(i, n){
        cin >> s[i].first;
        s[i].second = i+1;
    }
    vector<pair<string, int>> ans;
    rep(i, n){
        if(s[i].first.size() == td.size()){
            if(s[i].first == td) ans.push_back(s[i]);
            else{
                int cnt = 0;
                rep(j, td.size()){
                    if(s[i].first[j] != td[j]) break;
                    cnt++;
                }
                rep(j, td.size()){
                    if(s[i].first[td.size()-1 - j] != td[td.size()-1 - j]) break;
                    cnt++;
                }
                if(cnt == td.size()-1) ans.push_back(s[i]);
            }
        }
        else{
            int cnt = 0;
                rep(j, td.size()){
                    if(s[i].first[j] != td[j]) break;
                    cnt++;
                }
                rep(j, td.size()){
                    if(s[i].first[s[i].first.size()-1 - j] != td[td.size()-1 - j]) break;
                    cnt++;
                }
                if(cnt == min(s[i].first.size(), td.size())) ans.push_back(s[i]);
        }
    }
    //sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i].second << " ";
    }
    cout << endl;
    return 0;
}