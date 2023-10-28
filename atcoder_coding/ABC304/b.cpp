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
    int num = (log10(N) / 1) + 1;

    if(num < 4){
        cout << N << endl;
    }
    else{
        N = (N / (int)pow(10.0, (double)num-3)) * (int)pow(10.0, (double)num-3);
        cout << N << endl;
    }
    return 0;
}
/* 18'00" エラー多発させたから理由まとめる */