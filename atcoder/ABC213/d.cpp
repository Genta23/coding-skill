#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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

int dfs(int v, vector<vector<int>> &graph, vector<bool> &seen){ //vectorは値渡しが行われる
    cout << v+1 << " ";
    for(auto x : graph[v]){
        if(seen[x]) continue;
        seen[x] = true;

        dfs(x, graph, seen);
        cout << v+1 << " ";
    }
    return 0;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    rep(i, n) sort(graph[i].begin(), graph[i].end());

    vector<bool> seen(n);
    seen[0] = true;
    dfs(0, graph, seen);
    cout << endl;
    return 0;
}