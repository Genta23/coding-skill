#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int plt = -1;
    rep(i,8){
        int s;
        cin >> s;
        if(plt > s){
            cout << "No" << endl;
            return 0;
        }
        if(s < 100 || s > 675){
            cout << "No" << endl;
            return 0;
        }
        if(s % 25 != 0){
            cout << "No" << endl;
            return 0;
        }
        plt = s;
    }
    cout << "Yes" << endl;
    return 0;
}