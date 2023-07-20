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

    bool flag[1000000] = {false};
    //vector<bool> flag(N); vector初期値false
    //rep(i,N) flag[i]=false;
    rep(i,3*N){
        int a; cin >> a;
        if(flag[a-1]){
            cout << a << " ";
            flag[a-1] = false;
        }
        else{
            flag[a-1] = true;
        }
    }
    cout << endl;

    return 0;
}