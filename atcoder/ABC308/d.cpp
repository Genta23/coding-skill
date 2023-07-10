#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int H, W;
    cin >> H >> W;

    string str[H];
    rep(i,H){
        cin >> str[i];
    }
    bool visit[H][W];
    rep(i,H){
        rep(j,W){
            visit[i][j] = false;
        }
    }

    int clock = 0;
    /* 0 s, 1 n, 2 u, 3 k, 4 e*/
    int x=0, y=0;
    
    while(1){
        if(x==0 && y==0 && visit[y][x] == true){
            cout >> "No" >> endl;
            return 0;
        }
        if(visit[y][x] == true)
    }

    return 0;
}