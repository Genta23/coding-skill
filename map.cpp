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
bool flag[200005];
int main(){
    //int n; cin >> n;
    //vector<pair<ll, ll>> data(n); rep(i, n) cin >> data[i].first >> data[i].second;
    //sort(data.begin(), data.end());
    
    map<ll, ll> mp;
    mp[10] = 1;
    mp[8] = 7;
    mp[101] = 188;
    auto ite =  mp.lower_bound(11);
    cout << ite->first << " " << ite->second << endl;

    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    
    int d = distance(mp.begin(), ite);
    cout << d << endl;

    ite--;
    //iteは++とか--で操ることができる +1とかは使用することができない 2個先とかどうするんだろうか あまり意味ないのかな

    return 0;
}