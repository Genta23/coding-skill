#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int Ay, Ax;
    cin >> Ay >> Ax;

    string A[Ay];
    rep(i, Ay){
        cin >> A[i];
    }

    int ax_min = 1000, ax_max = 0, ay_min = 1000, ay_max = 0;
    rep(i, Ay){
        rep(j, Ax){
            if(A[i][j] == '#'){
                if(ax)
            }
        }
    }

    int By, Bx;
    cin >> By >> Bx;

    string B[By];
    rep(i, By){
        cin >> B[i];
    }

    int Xy, Xx;
    cin >> Xy >> Xx;

    string X[Xy];
    rep(i, Xy){
        cin >> X[i];
    }
    return 0;
}