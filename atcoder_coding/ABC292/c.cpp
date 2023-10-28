#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N; cin >> N;
    //Nが平方数の時の例外に冷静に対処できるなら線形時間で解くことができる それができないと2乗のオーダーになる
    //A <= Bという仮定をするなら √nを繰り下げたやつで十分　繰り上げるとAの方が大きくなる
    int cnt = 0;
    for(int i=1; i<=floor(N/2); i++){
        int left = 0;
        for(int j=1; j<=floor(sqrt(i)); j++){
            if(i%j == 0) left++;
        }
        if(sqrt(i) == floor(sqrt(i))) left = 2*left-1;
        else left = 2*left;

        int right = 0;
        for(int j=1; j<=floor(sqrt(N-i)); j++){
            if((N-i)%j == 0) right++;
        }
        if(sqrt(N-i) == floor(sqrt(N-i))) right = 2*right-1;
        else right = 2*right;

        //if(i == N/2) cnt += left * right; //これがミスの原因 奇数の時の判定がおかしくなっていた 整数に切り捨て勝手に入るのだるいって
        if(i == N/2.0) cnt += left * right;
        else cnt += 2 * left * right;
    }

    //組み合わせの積の計算をしていなかった

    cout << cnt << endl;
    return 0;
}