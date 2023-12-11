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
    int h, w; cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w)), b(h, vector<ll>(w));
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }
    rep(i, h){
        rep(j, w){
            cin >> b[i][j];
        }
    }

    vector<int> g1(h), o1(h), g2(w), o2(w);
    rep(i, h) g1[i] = i, o1[i] = i;
    rep(i, w) g2[i] = i, o2[i] = i;
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end());

    int ans = inf;
    do{
        do{
            int cnt = 0;
            vector<int> tmp1 = g1;
            for(int i=h-1; i>=0; i--){
                rep(j, h-1){
                    if((tmp1[j] == i) && (j < i)){
                        swap(tmp1[j], tmp1[j+1]);
                        cnt++;
                    }
                }
            }
            /*rep(i, h){
                rep(j, h){
                    if(tmp1[j] == i){
                        if(i != j){
                            swap(i, j);
                            cnt++;
                        }
                        break;
                    }
                }
            }*/
            vector<int> tmp2 = g2;
            for(int i=w-1; i>=0; i--){
                rep(j, w-1){
                    if((tmp2[j] == i) && (j < i)){
                        swap(tmp2[j], tmp2[j+1]);
                        cnt++;
                    }
                }
            }
            /*vector<int> tmp2 = g2; //これ自分の思い通りの挙動してなくないか 今回はこの転置数についての記事を書く
            rep(i, w){
                rep(j, w){
                    if(tmp2[j] == i){
                        if(i != j){
                            swap(i, j);
                            cnt++;
                        }
                        break;
                    }
                }
            }*/

            bool flag = true;
            rep(i, h){
                rep(j, w){
                    if(a[i][j] != b[g1[i]][g2[j]]) flag = false;
                }
            }
            if(flag){
                chmin(ans, cnt);
                /*rep(i, h) cout << g1[i] << " ";
                cout << endl;
                rep(i, w) cout << g2[i] << " ";
                cout << endl;*/
            }
            //std::cout << cnt << endl;
            //std::cout << "test" << endl;
        }while(next_permutation(g2.begin(), g2.end()));
    }while(next_permutation(g1.begin(), g1.end()));

    if(ans == inf){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}