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
    int n, m; cin >> n >> m;

    vector<int> a, b;
    rep(i, n){
        int temp; cin >> temp;
        a.push_back(temp);
    }
    rep(i, m){
        int temp; cin >> temp;
        b.push_back(temp);
    }
    int ai = 0, bi = 0;
    rep(i, n+m){
        if(ai == n){
            b[bi] = i+1;
            bi++;
        }
        else if(bi == m){
            a[ai] = i+1;
            ai++;
        }
        else if(a[ai] < b[bi]){
            a[ai] = i+1;
            ai++;
        }
        else{
            b[bi] = i+1;
            bi++;
        }
    }

    rep(i, n){
        cout << a[i] << " "; 
    }
    cout << endl;
    rep(i, m){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}