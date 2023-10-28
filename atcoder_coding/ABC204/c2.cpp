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
vector<bool> seen;
int cnt = 0;

int main(){
    int n, m; cin >> n >> m;

    //グラフの作成
    vector<vector<int>> graph(n+1);//1からnまでのなので、0番目はからになるでしょう
    rep(i, m){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        queue<int> que;
        vector<bool> seen(n+1);
        que.push(i);
        seen[i] = true;
        while(!que.empty()){
            cnt++;
            int v = que.front();
            que.pop();

            for(int i=0; i<graph[v].size(); i++){
                if(seen[graph[v][i]]) continue;

                seen[graph[v][i]] = true;
                que.push(graph[v][i]);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}