#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
struct Data{
    string s;
    int a;
}; //ここの;忘れがち

int main(){
    int N; cin >> N;
    vector<Data> data;
    rep(i, N){
        Data temp; cin >> temp.s >> temp.a;
        data.push_back(temp);
    }
    int min = -1, minPosition = -1; //1000だと小さすぎる
    rep(i, N){
        if(min == -1 || min > data[i].a){ //結局ここで分岐させたけど どんな数字で初期化すれば良いだろうか
            min = data[i].a;
            minPosition = i;
        }
    }
    rep(i, N){
        if(i+minPosition == N) minPosition -= N;
        cout << data[i+minPosition].s << endl;
    }
    

    return 0;
}
/* 16'23" 凡ミス */