#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int n; cin >> n;

    vector<int> data(200);

    rep(i, n){
        int temp; cin >> temp;
        data[temp%200]++;
    }

    long long sum = 0;
    rep(i, 200){
        long long m = data[i];
        sum += m*(m-1)/2;
    }

    cout << sum << endl;
    return 0;
}