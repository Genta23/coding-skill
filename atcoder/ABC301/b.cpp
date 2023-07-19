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
    int past = -1;
    vector<int> data;
    rep(i, N){
        int temp; cin >> temp;
        if(past == -1) data.push_back(temp); //最初は例外処理を行う
        else if(temp > past){
            rep(j, temp - past){
                data.push_back(past + 1 + j);
            }
        }
        else{
            rep(j, past - temp){
                data.push_back(past - 1 - j);
            }
        }
        past = temp;
    }
    rep(i, data.size()){
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
/* 6'43" */