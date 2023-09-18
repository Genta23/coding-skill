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
using namespace std;
typedef long long ll;
const int inf = 1e9;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int n; cin >> n;
    vector<ll> data(n);
    rep(i, n) cin >> data[i]; // dataの要素はintで十分
    sort(data.begin(), data.end());
    ll ans = 1;
    rep(i, n) ans = ans * max(ll(0), data[i] - i) % 1000000007; // ansがlongなので暗黙的方変換が起こる
    cout << ans << endl;
    return 0;
}