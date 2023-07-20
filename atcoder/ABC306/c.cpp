#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
struct Data{
    int value, num;
};
bool operator<(const Data &a, const Data &b) {
    if(a.value != b.value){
        return a.value < b.value; //オーバーロードに関してまとめてみる
    }
    else{
        return a.num < b.num;
    }
}
int main(){
    int N; cin >> N;

    map<Data, int> data;
    rep(i,3*N){
        Data temp;
        int a; cin >> a;
        temp.num = i+1;
        temp.value = a;

        data[temp] = i+1;
    }
    int count=0;
    for(auto i = data.begin(); i != data.end(); i++){
        //cout << i->first.value << " " << i->first.num << endl;
        if(count % 3 == 1){
            //cout << i->first.value << " ";
        }
        count++;
    }
    cout << endl;

    return 0;
}