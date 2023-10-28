#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int A, B;
    cin >> A >> B;
    A--, B--;

    if(A/3 == B/3 && (A%3)+1 == B%3){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;

}