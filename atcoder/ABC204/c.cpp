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

int cnt = 0;

int check(int node, vector<vector<int>> graph, vector<bool> &seen){
    cnt++;
    int size = graph[node].size();//このタイミングって大丈夫なのか??
    seen[node] = true;
    rep(i, size){
        if(!seen[graph[node][i]]){
            //このタイミングで変えるべきでは？？
            check(graph[node][i], graph, seen);
        }
    }
    return 0;
}

int main(){
    int n, m; cin >> n >> m;

    //グラフの作成
    vector<vector<int>> graph(n+1);//1からnまでのなので、0番目はからになるでしょう
    rep(i, m){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        vector<bool> seen(n+1);
        check(i, graph, seen);
    }
    cout << cnt << endl;
    return 0;
}