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
    int n = min(h, w);
    int ans[n];
    rep(i, n){
        ans[i] = 0;
    }

    vector<string> data;
    rep(i, h){
        string temp;
        cin >> temp;
        data.push_back(temp);
    }

    bool flag[h][w];
    rep(i, h){
        rep(j, w){
            flag[i][j] = false;
        }
    }
    /* 左上から右下にかけて調査 左上の頂点に始めに到達 そこから右下に探索 調査済みの場合はtrueをタグにする */
    rep(i, h){
        rep(j, w){
            if(data[i][j] == '#' && !flag[i][j]){
                int st_i = i, st_j = j;
                while(st_i < h && st_j < w && data[st_i][st_j] == '#'){
                    flag[st_i][st_j] = true;
                    st_i++, st_j++;
                }
                int d = st_i - i, ite_i = st_i - 1, ite_j = j;
                rep(k, d){
                    flag[ite_i][ite_j] = true;
                    ite_i--, ite_j++;
                }
                int size = (d-1)/2;
                ans[size-1]++;
            }
        }
    }

    rep(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}