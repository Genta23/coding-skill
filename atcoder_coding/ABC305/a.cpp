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
    if(N%5 == 0) cout << N << endl;
    else if(N%5 <= 2) cout << N - N%5 << endl;
    else cout << N - N%5 + 5 << endl;

    return 0;
}
/* 3'05" */