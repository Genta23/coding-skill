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
int compare(vector<string> a, vector<string> b, int size){ //これはやめて比較時の始点を調整する
    rep(i, size){
        if(a[i] != b[i]) return 1;
    }
    return 0;
}

int main(){
    int h, w; cin >> h >> w;
    
    string a, b; //もはや二次元配列ではなく、一つの文字列として捉える
    rep(i, h){
        string temp;
        cin >> temp;
        a += temp;
    }
    rep(i, h){
        string temp;
        cin >> temp;
        b += temp;
    }
    rep(i, h*w){
        int x = i % w;
        int y = i / h;
        bool flag = true;
        rep(j, h){
            rep(k, w){
                if(a[(w * ((y + j) % h)) + (x + k) % w] != b[w * j + k]){
                    flag = false;
                }
            }
        }
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

/* なぜこれが通らないかわかっていない */