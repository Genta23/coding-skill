#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N, K;
    cin >> N >> K;

    map<long long, long long> data;

    rep(i, N){
     long long a, b;
        cin >> a >> b;

        data[a] += b;
    }

    /*auto temp = data.rend();
    for (auto it = data.rbegin(); it != data.rend(); ++it) {
        if(temp != data.rend()){
            it->second += temp->second;//long必要か
            //これだと最後まで飲むパターンの実装ができていない
            if(it->second > K){
                cout << (it->first)+1 << endl;
                return 0;//return 忘れてたからこの後も動き続けていたという...
            }
        }
        temp = it;
    }*/

    auto temp = data.rend();
    for (auto it = data.rbegin(); it != data.rend(); ++it) {
        if(temp != data.rend()){
            it->second += temp->second;//long必要か
            //これだと最後まで飲むパターンの実装ができてない
        }
        if(it->second > K){
            cout << (it->first)+1 << endl;
            return 0;//return 忘れてたからこの後も動き続けていたという...
        }
        temp = it;
    }
    //そもそも初日で条件満たしているやつ
    cout << 1 << endl;
    /*for(auto i = data.begin(); i != data.end(); i++){
        //cout << i->second << " ";
        if(i->second <= K){
            cout << i->first << endl;
        }
        long intが必要になりそうなので修正
    }*/
    return 0;
}