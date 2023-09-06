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
    int n; cin >> n;
    vector<int> data(8);
    vector<int> result(200);
    int size = min(n, 8);
    rep(i, size){
        //int temp; cin >> temp;
        //data.push_back(temp);
        cin >> data[i]; //この2種類は異なるのと
    }

    for (int tmp = 0; tmp < (1 << size); tmp++) {
        bitset<8> s(tmp);
        int r = 0;
        rep(j, size){
            r += data[j]*s[j];
        }
        if(result[r%200] == 0){
            result[r%200] += tmp;
        }
        else{
            cout << "Yes" << endl;
            bitset<8> ans(result[r%200]);

            cout << ans.count() << " ";
            rep(i, size){
                if(ans[i]) cout << i+1 << " ";
            }
            cout << endl;

            cout << s.count() << " ";
            rep(i, size){
                if(s[i]) cout << i+1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

/*
for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
  bitset<ビット数> s(tmp);
  // (ビット列sに対する処理)
}
*/