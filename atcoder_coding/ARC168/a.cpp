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

template<typename T>
class BIT {
  private:
  int n;
  vector<T> d;
  
  public:
  BIT(int n=0):n(n),d(n+1) {}
  
  /// i以降の累積和にxを加算
  void add(int i, T x=1) {
    for (; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  
  /// 閉区間[1,i]の累積和を求める
  T sum(int i) {
    T x = 0;
    for (; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  
  /// 閉区間[l,r]の累積和を求める
  T sum(int l, int r) {
    return sum(r) - sum(l-1);
  }
};
long long inversion_number(const vector<long long>& v){
  auto u=v;
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  
  auto bit=BIT<long long>(u.size());
  
  long long res=0;
  for(int i=0; i<v.size(); i++){
    int rank=lower_bound(u.begin(), u.end(), v[i])-u.begin()+1;
    res+=i-bit.sum(rank);
    bit.add(rank);
  }
  return res;
}
int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> a(n);
    if(s[0] == '<') a[0] = 1;
    if(s[n-2] == '>') a[n-1] = 1;
    rep(i, n-2){
        if(s[i] == '>' && s[i+1] == '<'){
            a[i+1] = 1;
        }
    }

    rep(i, n){
        if(a[i] == 1){
            ll cnt = 1;
            int j = i;
            while(j <= n-2 && s[j] == '<'){
                cnt++;
                chmax(a[j+1], cnt);
                j++;
            }
            cnt = 1;
            j = i;
            while(j-1 >= 0 && s[j-1] == '>'){
                cnt++;
                chmax(a[j-1], cnt);
                j--;
            }
        }
    }
    a[0] = 1;
    rep(i, n-2){
        if(s[i] == '<'){
            a[i+1] = a[i] + 1;
        }
        else{
            a[i+1] = a[i] - 1;
        }
    }

    rep(i, n) cout << a[i] << " ";
    cout << endl;

    cout << inversion_number(a) << endl;
	
    return 0;
}