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
    int n; cin >> n;
    map<int, ll> data;
    rep(i, n){
        int tmp; cin >> tmp;
        data[tmp]++;
    }

    ll sum = 0;
    for (const auto& [key, value] : data){
        sum += value*(n-value); //ここintにするとオーバーフローします
    }
    //2回重複カウントをしているので
    cout << sum/2 << endl;

    return 0;
}