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

int main(){
    int t; cin >> t;
    rep(i, t){
        int r; cin >> r;
        int y = 0;

        bool flag = false;
        //x, yを特定する
        while(y*y < r){
            int x = r - y*y;
            if(x >= y){
                if(sqrt(x) == floor(sqrt(x))){
                    if(y == 0) flag = true;
                    que.push_back({x, y});
                }
            }
        }

        //最大公約数を計算する
        int min = inf;
        if(que.empty()) cout << "inf" << endl;
        while(!que.empty()){
            auto v = que.front();
            que.pop();
            //aの方がでかい
            int a = v.first, b = v.second;

            if(a == b){
                if(flag){
                    if(min > a*a) min = a*a;
                }
                else{
                    if(min > a*a)
                }
            }
            else{
                int g = gcd(a, b);
                a = a/g;
                b = b/g;
                if(a%2 == 0 || b%2 == 0){
                    if(min > g*g) min = g*g;
                }
                else{
                    if(min > g*g*2) min = g*g;
                }
            }
            cout << min << endl;
        }
        
    }
    return 0;
}