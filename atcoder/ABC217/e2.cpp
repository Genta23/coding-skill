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
#include <tuple>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    int q; cin >> q;
    min_priority_queue<int> que;
    bool flag = true;
    int ans;
    rep(i, q){
        int temp; cin >> temp;
        if(temp == 1){
            int x; cin >> x;
            if(flag){
                ans = x;
                flag = false;
            }
            else que.push(x);
        }
        else if(temp == 2){
            cout << ans << endl;
            if(que.size() == 0){
                flag = true;
            }
            else{
                ans = que.top();
                que.pop();
            }
        }
        else if(temp == 3){
            que.push(ans);
            ans = que.top();
            que.pop();
        }
    }
    return 0;
}