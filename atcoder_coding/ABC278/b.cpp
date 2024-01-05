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
#include <iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (ll i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    int h, m; cin >> h >> m;
    
    vector<bool> time(10000);
    rep(i, 24){
        rep(j, 60){
            time[i*100 + j] = true;
        }
    }

    while(1){
        int h_1 = h/10, h_2 = h%10;
        int m_1 = m/10, m_2 = m%10;

        if(time[h_1*1000+m_1*100+h_2*10+m_2]){
            cout << h << " " << m << endl;
            return 0;
        }

        if(h == 23 && m == 59){
            h = 0, m = 0;
        }
        else if(m == 59){
            h++, m = 0;
        }
        else{
            m++;
        }
    }
    return 0;
}