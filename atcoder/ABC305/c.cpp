#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
#define repBeginEnd(i, begin, end) for (int i=begin; i<=end; i++)

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int L=1e9, R=-1e9, U=1e9, D=-1e9;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            L = min(L, j);
            U = min(U, i);
            R = max(R, j);
            D = max(D, i);
        }
    }

    repBeginEnd(i, U, D)repBeginEnd(j, L, R){
        if(s[i][j] == '.'){
            cout << i+1 << " " << j+1 << endl;
            return 0;
        }
    }
}