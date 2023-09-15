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
    int n; cin >> n;

    int size = 1000000;
    vector<int> prime(size); //素数配列
    for(int i=1; i<=size; i++){ //計算量はNlogN 約数の個数が2個のものだけで配列を作成しよう
        int c = i;
        while(c <= size){
            prime[c-1]++;
            c += i;
        }
    }
   
    vector<int> prime_number;
    rep(i, size){ //計算量はN
        if(prime[i] == 2){
            prime_number.push_back(i+1);
        }
    }

    cout << prime_number.size() << endl;
    rep(i, 100){
        cout << prime_number[i] << endl;
    }


    return 0;
}