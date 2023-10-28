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
    vector<int> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    rep(i, 2*n) t[(i+1)%n] = min(t[(i+1)%n], t[i%n] + s[i%n]); //1e9 + 1e9なのでintで大丈夫
    rep(i, n) cout << t[i] << endl;
    return 0;
}