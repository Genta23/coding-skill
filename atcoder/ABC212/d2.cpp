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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    int q; cin >> q;
    ll offset = 0;
    min_priority_queue<ll> que;
    rep(i, q){
        int temp; cin >> temp;
        if(temp == 1){
            int x; cin >> x;
            que.push(x-offset);
        }
        else if(temp == 2){
            int x; cin >> x;
            offset += x;
        }
        else if(temp == 3){
            ll ans = que.top() + offset;
            que.pop();
            cout << ans << endl;
        }
    }
    return 0;
}