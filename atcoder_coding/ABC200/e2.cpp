#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
#include <bitset>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    long long n, k; cin >> n >> k;
    //1 -> N を 0 -> N-1に変換する
    long long N = n-1;

    //c : この番号までは調査しました。 条件に合うものは未だ発見できていません。
    long long c = 0, s, p;
    //K番目の数字が存在するsを発見する。(x + y + z = s)
    for(long long i=0; i<=3*N; i++){
        if(i <= N) p = (i+1)*(i+2)/2;
        else if(i <= 2*N) p = (-3*N*N + 3*N + 2)/2 + i*(3*N - i);
        else p = (3*N - i + 1)*(3*N - i + 2)/2;

        if(c+p >= k){ s = i; break; }

        c += p;
    }

    //xの値を決定する。
    int x;
    if(s <= N){
        x = 0;
        long long q = s+1;
        while(1){
            if(c+q >= k) break;
            x++; c += q; q--;
        }
    }
    else if(s <= 2*N){
        x = 0;
        long long q = 2*N + 1 - s;
        bool flag = true;
        while(1){
            if(c+q >= k) break;
            x++; c += q;

            if(q == N+1) flag = false;

            if(flag) q++;
            else q--;
        }
    }
    else{
        x = s - 2*N;
        long long q = 1;
        while(1){
            if(c+q >= k) break;
            x++; c += q; q++;
        }
    }

    //y, zの値を決定する。
    int y = 0, z;
    //c番目までに条件にあるものはありませんでした。c+1番目から探索開始
    c++;
    while(1){
        z = s - x - y;
        if(y >= 0 && y <= N && z >= 0 && z <= N){ //実行可能範囲内
            if(c == k) break;
            else{y++; c++;}
        }
        else y++; //実行可能範囲外ならば、yのみを更新し探索を続ける。
    }

    //最初に座標を(-1, -1, -1)ずらしたので、修正する。
    cout << x+1 << " " << y+1 << " " << z+1 << endl;


    return 0;
}