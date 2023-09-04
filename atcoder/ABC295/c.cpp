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

    map<int, int> data;
    rep(i, n){
        int temp; cin >> temp;
        data[temp]++;
    }

    int cnt = 0;
    for(auto itr = data.begin(); itr != data.end(); ++itr) {
        cnt += itr->second / 2;
    }
    cout << cnt << endl;
    return 0;
}