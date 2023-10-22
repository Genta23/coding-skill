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
    int l, q; cin >> l >> q;
    set<int> data;
    data.insert(0);
    data.insert(l);
    rep(i, q){
        int c, p; cin >> c >> p;
        if(c == 1) data.insert(p);
        else{
            auto itr = data.lower_bound(p);
            cout << *itr-*(--itr) << endl;
        }
    }
    return 0;
}