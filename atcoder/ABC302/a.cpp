#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    long long A, B, ans; cin >> A >> B;

    ans = A / B; //ansではなくAとしていたからA%Bの判定に影響が出て上手くいかなくなっていた。
    if(A % B != 0) ans++;
    cout << ans << endl;

    return 0;
}
/* 6'52" */