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

    vector<long long> max;
    bool flag = true; // true 元気 false 毒状態

    vector<int> p; // 0解毒剤 1毒
    vector<long long> score;

    rep(i,N){
        int a, b; cin >> a >> b;
        p.push_back(a);
        score.push_back(b);
    }

    int past0 = 0, past1 = 0, max0, max1;
    rep(i,N){
        if(flag == true){
            max = past
        }
        past = max
    }



    return 0;
} 