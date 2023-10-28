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
    //多くもらえる人とそうでない人の差は少なくとも1である
    ll n, k; cin >> n >> k;
    ll p = k/n, q = k%n;

    vector<ll> data(n), sort_data(n);
    rep(i, n){
        ll temp; cin >> temp;
        data[i] = temp;
        sort_data[i] = temp;
    }

    sort(sort_data.begin(), sort_data.end());
    ll mark = q == 0 ? 0 : sort_data[q-1]; //割り切れる場合の例外処理

    rep(i, n){
        if(data[i] <= mark) cout << p+1 << endl;
        else cout << p << endl;
    }
    return 0;
}