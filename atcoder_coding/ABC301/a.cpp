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
    string S; cin >> S;

    int countA = 0, countT = 0;
    rep(i, N){
        if(S[i] == 'A'){
            countA++;
        }
        if(S[i] == 'T'){
            countT++;
        }
    }
    if(countA > countT){
        cout << 'A' << endl;
    }
    else if(countA < countT){
        cout << 'T' << endl;
    }
    else{
        if(S[N-1] == 'A'){
            cout << 'T' << endl;
        }
        else{
            cout << 'A' << endl;
        }
    }

    return 0;
}