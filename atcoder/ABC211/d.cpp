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
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<int> dis(n, inf), cnt(n);
    queue<int> que;

    que.push(0);
    dis[0] = 0;
    cnt[0] = 1; //始点からそこまで最短で何通りの行き方があるか
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int x: graph[v]){
            if(dis[x] <= dis[v]) continue;
            if(dis[x] == inf) que.push(x); //挿入は未探索の場合のみ 計算を行ってから挿入ではなく、挿入してから計算で、問題は解決するc
            dis[x] = dis[v] + 1;
            cnt[x] = (cnt[x] + cnt[v])%1000000007;
        }
    }

    cout << cnt[n-1] << endl;
    return 0;
}