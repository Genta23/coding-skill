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

    vector<multiset<int>> box(n);
    map<int, set<int>> num;
    rep(r, q){
        int query; cin >> query;
        if(query == 1){
            int i, j; cin >> i >> j;
            box[j-1].insert(i);
            num[i].insert(j);
        }
        if(query == 2){
            int i; cin >> i;
            for(auto itr = box[i-1].begin(); itr != box[i-1].end(); ++itr) {
                cout << *itr << " ";      // イテレータの指す先のデータを表示
            }
            cout << endl;
        }
        if(query == 3){
            int i; cin >> i;
            for(auto itr = num[i].begin(); itr != num[i].end(); ++itr) {
                cout << *itr << " ";      // イテレータの指す先のデータを表示
            }
            cout << endl;
        }
    }
    return 0;
}