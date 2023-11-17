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

long double calR(vector<long double>& data){
    int k = data.size();
    vector<long double> O9(k);
    rep(i, k) O9[i] = powl(0.9, k-1-i);

    double a = 0.0;
    rep(i, k) a += O9[i]*data[i];

    double b = 0.0;
    rep(i, k) b += O9[i];

    cout << a/b << endl;

    double r = a/b - 1200/sqrt(k);

    return r;
}
#include <iomanip>  // iomanipヘッダーを含む
int main(){
    int n; cin >> n;
    vector<long double> p(n); rep(i, n) cin >> p[i];

    vector<long double> data;
    data = {1000, 1200};
    cout << fixed << setprecision(10) << calR(data) << endl;

    data = {1000, 660, 1200};
    cout << calR(data) << endl;

    data = {1300};
    cout << calR(data) << endl;

    data = {1200, 1000};
    cout << calR(data) << endl;

    data = {1000, 600};
    cout << fixed << setprecision(10) << calR(data) << endl;
    return 0;
}