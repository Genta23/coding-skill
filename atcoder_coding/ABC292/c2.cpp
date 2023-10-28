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
    //あまり難しく考えてなかった 2倍するとかしないとかはそこまで計算量に影響なかったりする (今回のオーダーの問題では)

    vector<int> divisor(N); //0初期化が入る
    rep(i, N){
        int c = i;
        if(i == 0){
            ;
        }
        else{
            while(c < N){
            divisor[c]++;
            c += i;
        }
        }
    }

    int cnt = 0;
    rep(i, N-1){
        cnt += divisor[1+i] * divisor[N-1-i];
    }
    cout << cnt << endl;

    return 0;
}