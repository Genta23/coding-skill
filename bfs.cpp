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

int main(){
    int r, c; cin >> r >> c;
    int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;

    vector<string> data;
    rep(i, r){
        string temp; cin >> temp;
        data.push_back(temp);
    }
}