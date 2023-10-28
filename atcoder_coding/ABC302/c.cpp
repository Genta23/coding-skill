#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
/* アルファベットを数え上げる関数 */
vector<int> separate(string data){
    int size = data.size();
    vector<int> alphabetCount(26);
    rep(i,size){
        alphabetCount[(data[i])-97]++;
    }
    return alphabetCount;
}
/* 問題読み間違え */
int main(){
    int n, m; cin >> n >> m;
    string past="";
    rep(i,n){
        string temp; cin >> temp;
        if(past == "") ;
        else{
            vector<int> pastVec(26), tempVec(26);
            pastVec = separate(past);
            tempVec = separate(temp);
            int count = 0;
            rep(j,26){
                count += abs(pastVec[j] - tempVec[j]);
            }
            if(count != 2) cout << "No" << endl;
            return 0;
        }
        past = temp;
    }
    cout << "Yes" << endl;
    return 0;
}
/* 問題を読み間違えた 並べ替えての意味が違った */