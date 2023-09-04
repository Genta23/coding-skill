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
    string s; cin >> s;
    
    int b_sum = 0;
    bool flag = false, ans_flag = false;
    rep(i, s.size()){
        if(s[i] == 'B'){
            b_sum += i%2;
        }
        if(s[i] == 'R' && !flag){
            flag = true;
        }
        else if(s[i] == 'R' && flag){
            flag = false;
        }
        if(s[i] == 'K' && flag){
            ans_flag = true;
        }
    }
    if(ans_flag && b_sum == 1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}