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
    vector<string> a(4), b(4), c(4);
    int count = 0;
    rep(i, 4) {
        cin >> a[i];
        if(a[i] == "#") count++;
    }
    rep(i, 4){
        cin >> b[i];
        if(b[i] == "#") count++;
    }
    rep(i, 4){
        cin >> c[i];
        if(c[i] == "#") count++;
    }

    rep(fi, 7){
        rep(fj, 7){
            /* 1枚目のシートを設定する */
            int memo[10][10] = {};
            rep(i, 4){
                rep(j, 4){
                    memo[3+i][3+j] = a[i][j];
                }
            }

            /* 2枚目のシートを被せる */
            rep(i, 4){
                rep(j, 4){
                    memo[fi+i][fj+j] = b[i][j];

                    /* 3枚目のシートを被せる */
                    rep(si, 7){
                        rep(sj, 7){
                            rep(ii, 4){
                                rep(jj, 4){
                                    memo[si+ii][sj+jj] = c[ii][jj];
                                }
                            }

                            /* 条件を満たすかチェックを行う */
                            int mini=inf, minj=inf, maxi=-inf, maxj=-inf, cnt=0;
                            rep(i, 10){
                                rep(j, 10){
                                    if(memo[i][j] == '#'){
                                        chmin(mini, i);
                                        chmin(minj, j);
                                        chmax(maxi, i);
                                        chmax(maxj, j);
                                        cnt++;
                                    }
                                }
                            }

                            if(cnt == count && abs(mini - maxi) == 4 && abs(minj - maxj) == 4){
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}