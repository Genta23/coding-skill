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
    min_priority_queue<int> sorted_que;
    queue<int> que;
    rep(i, q){
        int temp; cin >> temp;
        if(temp == 1){
            int x; cin >> x;
            que.push(x);
        }
        else if(temp == 2){
            if(sorted_que.size()){
                cout << sorted_que.top() << endl;
                sorted_que.pop();
            }
            else{
                cout << que.front() << endl;
                que.pop();
            }
        }
        else if(temp == 3){
            while(que.size()){ //これでもできるけど、可読性の観点からは!que.empty()の方がいいかも emptyは優先度付きキューにも使用することが可能
                sorted_que.push(que.front());
                que.pop();
            }
        }
    }
    return 0;
}