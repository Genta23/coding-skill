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
    int n, q; cin >> n >> q;

    multimap<int, int> boxToNum;
    rep(i, q){
        int query; cin >> query;
        if(query == 1){
            int i, j; cin >> i >> j;
            boxToNum.insert(make_pair(i, j)); //mapではboxToNum[i] = j;とかけたがmultimapでは使用不可
        }
    }
    if(boxToNum.find(2) != boxToNum.end()) {      // 見つかった場合
        cout << boxToNum.find(2)->first << " " << boxToNum.find(2)->second << endl;    //  キー、値を表示
    }
    return 0;
}