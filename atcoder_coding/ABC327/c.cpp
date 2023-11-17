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

int main(){
    int n = 9;
    int data[9][9];
    rep(i, n){
        rep(j, n){
            cin >> data[i][j];
        }
    }
    
    rep(i, n){
        set<int> st;
        rep(j, n){
            st.insert(data[i][j]);
        }
        if(st.size() != n){
            cout << "No" << endl;
            return 0;
        }
    }

    rep(i, n){
        set<int> st;
        rep(j, n){
            st.insert(data[j][i]);
        }
        if(st.size() != n){
            cout << "No" << endl;
            return 0;
        }
    }

    vector<pair<int, int>> a{{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
    rep(i, 9){
        set<int> st;
        rep(j, 3){
            rep(k, 3){
                st.insert(data[a[i].first + j][a[i].second + k]);
            }
        }
        if(st.size() != n){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}