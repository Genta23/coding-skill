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
    string s; int k; cin >> s >> k;
    sort(s.begin(), s.end());

    int cnt = 0;
    while(1){
        cnt++;
        if(cnt == k){
            cout << s << endl;
            break;
        }
        next_permutation(s.begin(), s.end());
    }
    return 0;
}