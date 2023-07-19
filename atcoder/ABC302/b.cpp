#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int h, w; cin >> h >> w;
    int x, y; //座標の管理を行う
    /* 進む方向を管理するベクトルを必要 */
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    vector<string> data;
    rep(i,h){
        string temp; cin >> temp;
        data.push_back(temp);
    }
    rep(i,h){
        rep(j,w){
            rep(k,8){
                string str = "";
                rep(l,5){
                    x = i + l*dx[k]; y = j + l*dy[k];
                    if(x<0 || x >= h || y<0 || y >= w) break;
                    str+=data[x][y];//文字を追加する
                }
                if(str == "snuke"){
                    rep(l,5){
                        x = i + l*dx[k]; y = j + l*dy[k];
                        cout << x+1 << " " << y+1 << endl;
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}