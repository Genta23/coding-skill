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

    vector<vector<int>> a, b;
    rep(i, n){
        vector<int> vec_temp;
        rep(j, n){
            int temp;
            cin >> temp;
            vec_temp.push_back(temp);
        }
        a.push_back(vec_temp);
    }
    rep(i, n){
        vector<int> vec_temp;
        rep(j, n){
            int temp;
            cin >> temp;
            vec_temp.push_back(temp);
        }
        b.push_back(vec_temp);
    }

    /* 0時 */
    bool flag = true;
    rep(i, n){
        rep(j, n){
            if(a[i][j] == 1 && b[i][j] == 0) flag = false;
        }
    }
    if(flag){
        cout << "Yes" << endl;
        return 0;
    }

    /* 3時 */
    flag = true;
    rep(i, n){
        rep(j, n){
            if(a[j][n-1 - i] == 1 && b[i][j] == 0) flag = false;
        }
    }
    if(flag){
        cout << "Yes" << endl;
        return 0;
    }

    /* 6時 */
    flag = true;
    rep(i, n){
        rep(j, n){
            if(a[n-1 - i][n-1 - j] == 1 && b[i][j] == 0) flag = false;
        }
    }
    if(flag){
        cout << "Yes" << endl;
        return 0;
    }

    /* 9時 */
    flag = true;
    rep(i, n){
        rep(j, n){
            if(a[n-1 - j][i] == 1 && b[i][j] == 0) flag = false;
        }
    }
    if(flag){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}