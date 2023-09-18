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
const int inf = 1e9;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int q; cin >> q;
    multiset<ll> box;
    rep(i, q){
        int temp; cin >> temp;
        if(temp == 1){
            int num; cin >> num;
            box.insert(num);
        }
        else if(temp == 2){
            int plus; cin >> plus;
            for(auto itr = box.begin(); itr != box.end(); ++itr){
                cout << *itr << endl;
            }
        }
        else{
            cout << *box.begin() << endl;
            box.erase(box.begin());
        }
    }
    return 0;
}