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
    int k; cin >> k;
    //int count[10] = {9, 45, 120, 210, 252, 210, 120, 45, 10, 1};

    vector<ll> list;
    for (int bit = 1; bit < (1<<9); ++bit) {
        bitset<9> s(bit);
        if(s.count() == 0) continue;
        int num = 0;
        int p = 1;
        rep(i, 9){
            if(s[i]){
                num += (i+1)*p;
                p *= 10;
            }
        }
        list.push_back(num);
        list.push_back((ll)num * 10);
    }

    sort(list.begin(), list.end());

    cout << list[k-1] << endl;
    return 0;
}