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
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    ll n, q; cin >> n >> q;
    vector<ll> data;
    rep(i, n){
        ll tmp; cin >> tmp;
        data.push_back(tmp);
    }
    vector<ll> k;
    rep(i, q){
        ll tmp; cin >> tmp;
        k.push_back(tmp);
    }
    vector<ll> c(n);
    rep(i, n){
        if(i == 0) c[i] = data[i] - 1;
        else{
            c[i] = c[i-1] + data[i] - data[i-1] - 1;
        }
    }
    rep(i, q){
        if(c[n-1] < k[i]) cout << data[n-1] + k[i] - c[n-1] << endl;
        else {
            //条件を満たす要素がどこにあるかを探索する
            int pos = lower_bound(c.begin(), c.end(), k[i]) - c.begin();
            cout << data[pos] - 1 - (c[pos] - k[i]) << endl;
        }
    }
    return 0;
}