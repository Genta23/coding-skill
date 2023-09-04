#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0, ans = -1;
    bool flag = false;
    rep(i, n){
        if(s[i] == 'o'){
            cnt++;
            if(ans < cnt){
                ans = cnt;
            }
        }
        else{
            flag = true;
            cnt = 0;
        }
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl; /* oが連続する例外を判定 */
    return 0;
}
/* C問題レベルではない 3分あればできる問題 */