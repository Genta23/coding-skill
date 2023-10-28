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
#include <deque>
using namespace std;
typedef long long ll;
const int inf = 1e9;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int q; cin >> q;
    deque<int> dq;
    rep(i, q){
        int temp; cin >> temp;
        if(temp == 1){
            int x; cin >> x;
            dq.push_back(x);
        }
        else if(temp == 2){
            cout << dq.front() << endl;
            dq.pop_front();
        }
        else{
            sort(dq.begin(), dq.end());
        }

    }
    return 0;
}