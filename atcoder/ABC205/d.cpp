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
    data.push_back(0);
    rep(i, n){
        ll tmp; cin >> tmp;
        data.push_back(tmp);
    }
    sort(data.begin(), data.end());
    vector<ll> k;
    rep(i, q){
        ll tmp; cin >> tmp;
        k.push_back(tmp);
    }

    rep(i, q){
        ll left = 0, right = data.size()+1;
        ll center = (left + right) / 2;
        while(left < right-1){
            if(data[center]-1 - center >= k[i]){
                right = center;
                center = (left + right) / 2;
            }
            else{
                left = center;
                center = (left + right) / 2;
            }
        }
        cout << (k[i] - (data[left]-1 - left-1)) << endl;
        //cout << " " << data[left] << endl;
    }


    return 0;
}