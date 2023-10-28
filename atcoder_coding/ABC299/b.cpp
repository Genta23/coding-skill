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
    int n, t; cin >> n >> t;

    vector<int> color, value;
    rep(i, n){
        int c; cin >> c;
        color.push_back(c);
    }
    rep(i, n){
        int v; cin >> v;
        value.push_back(v);
    }
    int max = 0, winner;
    bool flag = false;
    rep(i, n){
        if(color[i] == t && value[i] > max){
            max = value[i];
            winner = i+1;
            flag = true;
        }
    }
    if(flag){
        cout << winner << endl;
        return 0;
    }
    
    rep(i, n){
        if(color[i] == color[0] && value[i] > max){
            max = value[i];
            winner = i+1;
        }
    }
    cout << winner << endl;
    return 0;
}