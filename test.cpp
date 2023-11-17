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
#include <tuple>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;

auto genta_unique(vector<int> &data){
    auto itr = data.begin();
    rep(i, data.size()){
        if(*itr == data[i]) continue;
        itr++;
        *itr = data[i];
    }
    return ++itr;
}

int main(){
    /*vector<int> data = {1, 2, 3, 3, 2, 2, 2, 7};

    auto v = genta_unique(data);

    data.erase(v, data.end());
    rep(i, data.size()) cout << data[i] << " ";
    cout << endl;

    min_priority_queue<int> que;
    que.push(0);
    int cnt = 0;
    while(!que.empty()){
        auto& v = que.top(); que.pop();
        cout << "step" << cnt << " " << que.size() << endl;
        cout << v << " " << que.size() << endl;
        que.push(100);
        cout << v << " " << que.size() << endl;
        que.push(v);
        cout << v << " " << que.size() << endl;

        cnt++;
        if(cnt == 20) break;
    }*/
    return 0;
}