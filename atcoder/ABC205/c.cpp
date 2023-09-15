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
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int a, b, c; cin >> a >> b >> c;
    c = c%2;
    if(a >= 0 && b >= 0){
        if(a > b) cout << '>' << endl;
        else if(a == b) cout << '=' << endl;
        else cout << '<' << endl;
    }
    else if(a*b < 0){
        if(c == 0){
            if(abs(a) > abs(b)) cout << '>' << endl;
            else if(abs(a) == abs(b)) cout << '=' << endl;
            else cout << '<' << endl;
        }
        else{
            if(a > 0) cout << '>' << endl;
            else cout << '<' << endl;
        }
    }
    //片方が0の場合を考えることができてない //a = 0, b = -3のような状況を考慮できていない
    else{
        if(abs(a) == abs(b)) cout << '=' << endl;//ここをミスった else ifにしなかったから2回出力するものがあった どんなに条件やってもelseに引っかかるようになる
        else if(c == 0){
            if(abs(a) > abs(b)) cout << '>' << endl;
            else cout << '<' << endl;
        }
        else{
            if(abs(a) > abs(b)) cout << '<' << endl;
            else cout << '>' << endl;
        }
    }
    return 0;
}