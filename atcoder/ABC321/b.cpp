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
    int n, x; cin >> n >> x;
    vector<int> a(n-1);
    int sum = 0;
    rep(i, n-1) {
        int temp; cin >> temp;
        a[i] = temp;
        sum += temp;
    }

    sort(a.begin(), a.end());

    sum -= (a[0] + a[n-2]);
    int d = x - sum;

    //もしすでに達成していたら
    if(sum + a[0] >= x){
        cout << 0 << endl;
    }
    else if(d <= a[n-2]){ //イコールのつけ忘れい！！
        cout << d << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}