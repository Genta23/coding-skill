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

    if(c == 0){
        if(abs(a) > abs(b)) puts(">");
        else if(abs(a) == abs(b)) puts("=");
        else puts("<");
    }
    else{
        if(a > b) puts(">");
        else if(a == b) puts("=");
        else puts("<");
    }
    return 0;
}