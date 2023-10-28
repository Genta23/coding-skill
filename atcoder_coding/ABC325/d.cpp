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
    vector<pair<ll, ll>> data(n); rep(i, n) cin >> data[i].second >> data[i].first;
    sort(data.begin(), data.end());

    map<ll, ll> mp;
    mp[-100] = 0;
    mp[5*infl] = 0; //範囲外にならないような対策
    ll ans = n;
    rep(i, n){
        auto it = mp.upper_bound(data[i].second); it--;
        if(data[i].second > it->first + it->second){ //この時は範囲外にある
            if(data[i].second - (it->first + it->second) == 1) mp[it->first]++;
            else mp[data[i].second] = 0, it++;
        }
        else{ // この時は範囲内にある
            if(data[i].second + data[i].first <= it->first + it->second) ans--;
            else mp[it->first]++;
        }

        //merge
        if(it->first + it->second - (++it)->first == -1){ //次の要素の差がほとんどない場合
            ll tmp = it->second;
            it = mp.erase(it); it--;
            mp[it->first] += tmp + 1;
        }
    }
    cout << ans << endl;
    return 0;
}