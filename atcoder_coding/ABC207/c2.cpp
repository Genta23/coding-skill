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
#define rep(i,n) for (int i=0; i<n; i++)
struct Data{
    ll l, r;
};

int main(){
    // 全て閉区間に戻す
    // 全探索で十分かも
    int n; cin >> n;
    vector<Data> data(n);
    rep(i, n){
        int t; cin >> t >> data[i].l >> data[i].r;
        if(t == 1){
            data[i].l *= 2;
            data[i].r *= 2;
        }
        else if(t == 2){
            data[i].l *= 2;
            data[i].r *= 2;
            data[i].r--;
        }
        else if(t == 3){
            data[i].l *= 2;
            data[i].l++;
            data[i].r *= 2;
        }
        else{
            data[i].l *= 2;
            data[i].l++;
            data[i].r *= 2;
            data[i].r--;
        }
    }

    int ans = 0;
    rep(i, n){
        rep(j, n){
            if(i >= j) continue;//i == jで同じときのカウント防止 i<jと指向性を持たせて二重数え上げ防止
            // 衝突判定
            if(data[i].r < data[j].l) continue;
            if(data[j].r < data[i].l) continue;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}