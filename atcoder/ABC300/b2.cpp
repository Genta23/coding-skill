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
        temp += temp;
        a.push_back(temp);
    }
    rep(i, h){
        a.push_back(a[i]);
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
                    if(a[i_st + i][j_st + j] != b[i][j]) flag = false;
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