#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
struct Data{
    long double p;
    int id;
};
bool operator<(const Data &a, const Data &b) {
    if(a.p != b.p){
        return a.p > b.p; //オーバーロードに関してまとめてみる
    }
    else{
        return a.id < b.id;
    }
}
int main(){
    int N;
    cin >> N;
    
    map<Data, int> prob;
    rep(i,N){
        long double a, b;
        cin >> a >> b;
        long double p = a / (a + b);
        Data temp;
        temp.p = p;
        temp.id = (i+1);
        prob[temp] = (i+1);
    }

    for(auto i = prob.begin(); i != prob.end(); i++){
        cout << i->second << " ";
    }
    cout << endl;
    return 0;
}