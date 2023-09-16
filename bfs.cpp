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

/*int main(){
    //辺の数 n
    int n;

    vector<vector<int>> graph(n);
    // 無向辺のグラフを作成する
    rep(i, n){
        int a, b; cin >> a >> b;
        // 1からnの辺と考えると 辺の番号から-1したものがその辺のタグになる
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<int> seen(n);
    queue<int> que;

    // 始点を挿入する 始点を探索済にする
    que.push(0);
    seen[0] = true;
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int i=0; i<graph[v].size(); i++){
            if(seen[graph[v][i]]) continue;

            seen[graph[v][i]] = true;
            que.push(graph[v][i]);
        }
    }


    return 0;
}*/
struct Data
{
    int y, x;
};


int main(){
    int seen[50][50];
    rep(i, 50) rep(j, 50) seen[i][j] = -1;
    int r, c; cin >> r >> c;
    int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;

    vector<string> data;
    rep(i, r){
        string temp; cin >> temp;
        data.push_back(temp);
    }

    queue<Data> que;
    que.push({sy-1, sx-1});
    seen[sy-1][sx-1] = 0;
    while(!que.empty()){
        Data v = que.front();
        que.pop();

        if(data[v.y+1][v.x] == '.' && seen[v.y+1][v.x] == -1) {
            que.push({v.y+1, v.x});
            seen[v.y+1][v.x] = seen[v.y][v.x] + 1;
        }
        if(data[v.y][v.x+1] == '.' && seen[v.y][v.x+1] == -1) {
            que.push({v.y, v.x+1});
            seen[v.y][v.x+1] = seen[v.y][v.x] + 1;
        }
        if(data[v.y-1][v.x] == '.' && seen[v.y-1][v.x] == -1) {
            que.push({v.y-1, v.x});
            seen[v.y-1][v.x] = seen[v.y][v.x] + 1;
        }
        if(data[v.y][v.x-1] == '.' && seen[v.y][v.x-1] == -1) {
            que.push({v.y, v.x-1});
            seen[v.y][v.x-1] = seen[v.y][v.x] + 1;
        }
    }
    cout << seen[gy-1][gx-1] << endl;
    return 0;
}