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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, min = inf;
    while(i < n && j < m){
        if(min > abs(a[i] - b[j])) min = abs(a[i] - b[j]);

        if(a[i] <= b[j]) i++;
        else j++;
    }
    cout << min << endl;
    return 0;
}