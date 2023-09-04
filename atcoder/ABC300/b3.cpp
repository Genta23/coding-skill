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
    int h, w; cin >> h >> w;

    vector<string> a, b;
    rep(i, h){
        string temp;
        cin >> temp;
        a.push_back(temp);
    }
    rep(i, h){
        string temp;
        cin >> temp;
        b.push_back(temp);
    }
    rep(i_st, h){
        rep(j_st, w){
            bool flag = true;
            rep(i, h){
                rep(j, w){
                    if(a[(i_st + i)%h][(j_st + j)%w] != b[i][j]) flag = false;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

/* 感想 */
//無理して一次元配列を使用せずに二次元配列を使用する 使用するメモリ量は同じなので考え方の問題
//マップを繋げて4倍の大きさのものを使用することで始め解くことができたが、繋げないでmodで回すという方法があった