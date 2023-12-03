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

int main(){
    long long n, m; cin >> n >> m;
    vector<long long> a(m); 
    for(int i=0; i<m; i++) cin >> a[i];
    int q; cin >> q;
    vector<pair<long long, long long>> data(q); for(int i=0; i<q; i++) cin >> data[i].first >> data[i].second;

    long long cnt = 1, pos = a[0];
    vector<long long> start, goal;
    for(int i=1; i<m; i++){
        if(a[i] == pos + cnt){
            cnt++;
        }
        else{
            start.push_back(pos);
            goal.push_back(pos + cnt);
            cnt = 1;
            pos = a[i];
        }
    }
    start.push_back(pos);
    goal.push_back(pos + cnt);

    //rep(i, comp.size()) cout << comp[i].first << " " << comp[i].second << endl;

    for(int i=0; i<q; i++){
        long long l = data[i].first, r = data[i].second;
        auto it = upper_bound(start.begin(), start.end(), l);
        long long d0 = distance(start.begin(), it);
        if(d0 == 0){
            cout << l << endl;
        }
        else if(d0 > 0){
            if(l < goal[d0-1]){
                //　範囲内
                if(r < goal[d0-1]){
                    cout << -1 << endl;
                }
                else{
                    cout << goal[d0-1] << endl;
                }
            }
            else{
                // 範囲外
                cout << l << endl;
            }
        }
    }
    return 0;
}