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
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    map<ll, ll> data;
    rep(i, n){
        ll a, b; cin >> a >> b;
        data[a] += b;
    }

    ll pos = 0;
    for (const auto& [key, value] : data){
        //std::cout << key << " => " << value << "\n";
        //金が足りる場合
        if(key - pos <= k){
            k = k - (key - pos) + value;
            pos = key;
        }
        //足りない場合
        else break;
    }
    cout << pos + k << endl;



    return 0;
}