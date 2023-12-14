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
    ll xa, ya, xb, yb, xc, yc; cin >> xa >> ya >> xb >> yb >> xc >> yc;

    ll xm, ym, xm2, ym2;
    bool flag = false;

    ll ans = 0;
    if(xb == xc){ //上下運動
        xm = xb;
        if(yb < yc){
            ym = yb - 1;
            if(xa == xb){
                if(ya > xb) ans += 2;
            }
        }
        else{
            ym = yb + 1;
            if(xa == xb){
                if(ya < xb) ans += 2;
            }
        }
    }
    else if(yb == yc){ //左右運動
        ym = yb;
        if(xb < xc){
            xm = xb - 1;
            if(ya == yb){
                if(xa > xb) ans += 2;
            }
        }
        else{
            xm = xb + 1;
            if(ya == yb){
                if(xa < xb) ans += 2;
            }
        }
    }
    else{ 
        flag = true;
        ans += 2;
        if(xb < xc){
            if(yb < yc){
                xm = xb, ym = yb - 1;
                xm2 = xb - 1, ym2 = yb;
            }
            else{
                xm = xb, ym = yb + 1;
                xm2 = xb - 1, ym2 = yb;
            }
        }
        else{
            if(yb < yc){
                xm = xb, ym = yb - 1;
                xm2 = xb + 1, ym2 = yb;
            }
            else{
                xm = xb, ym = yb + 1;
                xm2 = xb + 1, ym2 = yb;
            }
        }
    }
    
    if(!flag) ans += abs(xa - xm) + abs(ya - ym);
    if(flag) ans += min(abs(xa - xm) + abs(ya - ym), abs(xa - xm2) + abs(ya - ym2));

    ans += abs(xb - xc) + abs(yb - yc);
    
    cout << ans << endl;
    return 0;
}