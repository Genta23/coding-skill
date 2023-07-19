#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    /* 文字列に順序づけを行ってソートすると良さそう ->　その上ソートを行うことができれば、線形時間での探索が可能になる */
    int N; cin >> N;
    map<string, int> data;
    rep(i, N){
        string temp; cin >> temp;
        string reverseTemp = temp;
        reverse(reverseTemp.begin(), reverseTemp.end());
        if(data.find(temp) != data.end()){ //keyが存在した場合
            data[temp]++;
        }
        else if(data.find(reverseTemp) != data.end()){ //reverse Keyが存在した場合
            data[reverseTemp]++;
        }
        else{
            data[temp]++;
        }
    }
    cout << data.size() << endl;

    return 0;
}