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
    multiset<int> data;
    rep(i, q){
        int temp; cin >> temp;
        if(temp == 1){
            int x; cin >> x;
            data.insert(x);
        }
        else if(temp == 2){
            int x, c; cin >> x >> c;
            for(auto itr = data.begin(); itr != data.end();) { //ここの計算量ってどうなっているんだっけ
                if(c == 0) break;
                if(itr == data.end()) break;
                if(*itr == x){
                    itr = data.erase(itr);
                    c--;
                }
                else itr++;
            }
        }
        else if(temp == 3){
            cout << *data.rbegin() - *data.begin() << endl;
        }
    }
    return 0;
}