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
    int n, k; cin >> n >> k;

    set<int> data;
    rep(i, n){
        int temp; cin >> temp;
        data.insert(temp);
    }

    rep(i, k){
        if(!data.count(i)){
            cout << i << endl;
            return 0;
        }
    }
    cout << k << endl;
    return 0;
}