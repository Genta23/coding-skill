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
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    string s; cin >> s;
    int a = 0, b = 0;
    rep(i, 10){
        if(s[i] == 'o') a++;
        if(s[i] == '?') b++;
    }

    if(a >= 5) cout << 0 << endl;
    else if(a == 4) cout << 24 << endl;
    else if(a == 3){
        if(b >= 1) cout << 24*b + 36 << endl;
        else cout << 36 << endl;
    }
    else if(a == 2){
        if(b >= 2) cout << 12*pow(b,2) + 24*b + 14 << endl;
        else if(b == 1) cout << 36*b + 14 << endl;
        else cout << 14 << endl;
    }
    else if(a == 1){
        if(b >= 3) cout << 4*pow(b,3) + 6*pow(b,2) + 4*b + 1 << endl;
        else if(b == 2) cout << 18*pow(b,2) - 4*b + 1 << endl;
        else if(b == 1) cout << 14*b + 1 << endl;
        else cout << 1 << endl;
    }
    else cout << pow(b,4) << endl;

    return 0;
}
//これコードとしては最悪な手法をやったよね
//PCの利点を一切用いないという笑