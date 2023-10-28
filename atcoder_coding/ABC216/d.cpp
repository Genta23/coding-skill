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
struct Data
{
    int f, s;
};


int main(){
    // データ取得
    int n, m; cin >> n >> m;
    vector<queue<int>> data(m);
    rep(i, m){
        int k; cin >> k;
        rep(j, k){
            int temp; cin >> temp;
            data[i].push(temp-1); //ここで1個ずらす
        }
    }

    vector<int> memo(n, -1);
    queue<Data> que;
    // 初期化
    rep(i, m){
        if(memo[data[i].front()] == -1) memo[data[i].front()] = i;
        else que.push({memo[data[i].front()], i});
    }

    while(!que.empty()){
        Data v = que.front();
        que.pop();

        memo[data[v.f].front()] = -1;

        data[v.f].pop();
        data[v.s].pop();

        if(!data[v.f].empty()){ // これを付けないとsegmentation faultになる
            if(memo[data[v.f].front()] == -1) memo[data[v.f].front()] = v.f;
            else que.push({memo[data[v.f].front()], v.f});
        }

        if(!data[v.s].empty()){
            if(memo[data[v.s].front()] == -1) memo[data[v.s].front()] = v.s;
            else que.push({memo[data[v.s].front()], v.s});
        }
    }

    bool flag = true;
    rep(i, n) if(memo[i] != -1) flag = false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}