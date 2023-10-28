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
using namespace std;
typedef long long ll;
const int inf = 1e9;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    ll n; cin >> n;
    bitset<120> bit(n);
    string ans;

    bool flag = false;
    rep(i, 120){
        if(bit[120 - 1 - i]) flag = true;
        if(!flag) continue;

        if(bit[120 - 1 - i]) ans += "AB";
        else ans += "B";
    }
    ans.pop_back(); //どちらも最後に"B"が挿入されるのは、ビットシフトが起こるからであり、最後は例外とする必要がある。
    cout << ans << endl;
    return 0;
}