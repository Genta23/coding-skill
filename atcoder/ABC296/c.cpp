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
    int n, x; cin >> n >> x;

    set<int> data;
    rep(i, n){
        int temp; cin >> temp;
        data.insert(temp);
    }
    
    // このループは線形探索なので、計算量はN
    for(auto itr = data.begin(); itr != data.end(); ++itr) {
        //cout << *itr << endl;
        int dj = *itr + x;
        // setを使用するとこの部分の探索がlog(N)
        if(data.find(dj) != data.end()){
            cout << "Yes" << endl;
            return 0;
        }
    }
    // 結果としてNlog(N)の計算量となる
    cout << "No" << endl;
    return 0;
}