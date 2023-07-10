#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N, M;
    vector<string> C, D;
    vector<int> P;
    map<string, int> price;

    cin >> N >> M;

    rep(i,N){
        string c;
        cin >> c;
        C.push_back(c);
    }
    rep(i,M){
        string d;
        cin >> d;
        D.push_back(d);
    }
    rep(i,M+1){
        int p;
        cin >> p;
        P.push_back(p);
    }
    rep(i,M){
        price[D[i]] = P[i+1];
    }

    int sum=0;
    rep(i,N){
        if(price.find(C[i]) == price.end()){
            sum += P[0];
        }
        else{
            sum += price[C[i]];
        }
    }
    cout << sum << endl;
    return 0;
}