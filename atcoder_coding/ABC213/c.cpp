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
    int h, w, n; cin >> h >> w >> n;
    
    vector<int> data_a(n), data_b(n);
    set<int> a, b;
    rep(i, n) {
        int p, q; cin >> p >> q;
        data_a[i] = p;
        data_b[i] = q;
        a.insert(p);
        b.insert(q);
    }

    map<int, int> s, t;
    int cnt = 1;
    for(auto x : a){
        s[x] = cnt;
        cnt++;
    }
    cnt = 1;
    for(auto x : b){
        t[x] = cnt;
        cnt++;
    }

    rep(i, n){
        cout << s[data_a[i]] << " " << t[data_b[i]] << endl;
    }
    return 0;
}