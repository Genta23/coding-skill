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
    int n, k; cin >> n >> k;
    vector<int> data(n);
    map<int, int> count;
    rep(i, n){
        int temp; cin >> temp;
        data[i] = temp;
        count[temp] = 0;
    }

    int cnt = 0, max;
    rep(i, k){
        if(count[data[i]] == 0) cnt++; // 最初の範囲の種類を測る
        count[data[i]]++;
    }

    max = cnt;
    rep(i, n-k+1){
        if(i == 0) continue;
        
        /* このコードだと同じタイミングで同じ色が出入りしたらバグるかも
        count[data[i -1]]--;
        count[data[i+k-1]]++;

        if(count[data[i -1]] == 0) cnt--;
        if(count[data[i+k-1]] == 1) cnt++;*/
        count[data[i -1]]--;
        if(count[data[i -1]] == 0) cnt--;

        count[data[i+k-1]]++;
        if(count[data[i+k-1]] == 1) cnt++;

        if(max < cnt) max = cnt;
    }
    cout << max << endl;
    return 0;
}