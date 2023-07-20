#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N; cin >> N;

    string str; cin >> str;

    rep(i,N){
        cout << str[i] << str[i];
    }
    cout << endl;
    return 0;
}