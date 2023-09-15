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
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    long long n; cin >> n;
    long long as[100009] = {0}, bcs[100009] = {0};

    vector<long long> ad(n), bd(n), cd(n);
    rep(i, n){
        long long temp; cin >> temp;
        ad[i] = temp;
        as[temp]++;
    }
    rep(i, n){
        long long temp; cin >> temp;
        bd[i] = temp;
    }
     rep(i, n){
        long long temp; cin >> temp;
        cd[i] = temp;
        bcs[bd[temp-1]]++; //0始まりなのでここは調整が必要
    }
    long long sum = 0;
    rep(i, 100009){
        sum += as[i]*bcs[i];
    }
    cout << sum << endl;
    return 0;
}