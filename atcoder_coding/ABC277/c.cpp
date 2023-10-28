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

int check(int m, map<int, set<int>> data, map<int, bool> flag){
    auto itr = flag.find(m);
    if(itr -> second) return 0;

    auto itr = data.find(m);
    /*for(auto i = (itr->second).begin(); i != (itr->second).end(); ++i){

    }*/
    //ぐっちゃになってしまっている これは使うことができないと思う 新しいアイデアを実装してみる
}
int main(){
    int n; cin >> n;

    map<int, set<int>> data;
    map<int, bool> flag;
    flag[1] = true;
    rep(i, n){
        int a, b; cin >> a >> b;
        data[a].insert(b);
        data[b].insert(a);
        flag[a] = false;
        flag[b] = false;
    }
    if(data.find(1) != data.end()){
        cout << 1 << endl;
        return 0;
    }
    check(1, data, flag);

    return 0;
}