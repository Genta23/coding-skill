#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N;
    cin >> N;

    int num[7*N];
    rep(i, 7*N){
        cin >> num[i];
    }

    rep(i, N){
        int sum=0;
        rep(j, 7){
            sum += num[7*i + j];
        }
        cout << sum << " " ;
    }
    cout << endl;
    return 0;
}