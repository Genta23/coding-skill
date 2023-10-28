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
const int inf = 1e9;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int n, q; cin >> n >> q;
    vector<vector<int>> graph(n);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    //vector<int> c(n), d(n); //これでRE めっちゃ時間使ったわ
    vector<int> c(q), d(q);
    rep(i, q) cin >> c[i] >> d[i];

    /*vector<int> dis(n);
    rep(i, n) dis[i] = -1;*/
    vector<int> dis(n, -1);

    queue<int> que;
    // 始点を挿入する 始点を探索済にする
    que.push(0);
    dis[0] = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int x: graph[v]){
            if(dis[x] != -1) continue;

            dis[x] = dis[v] + 1;
            que.push(x);
        }
    }

    rep(i, q){
        if(dis[c[i]-1]%2 == dis[d[i]-1]%2) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
    return 0;
}