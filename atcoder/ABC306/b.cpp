#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    unsigned long long num = 0;
    unsigned long long two = 1;
    rep(i,64){
        int temp;
        cin >> temp;
        num += two * temp;
        two *= 2;
    }
    cout << num << endl;
    return 0;
}