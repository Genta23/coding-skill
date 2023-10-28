#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    /* 文字列に順序づけを行ってソートすると良さそう ->　その上ソートを行うことができれば、線形時間での探索が可能になる */
    int N; cin >> N;
    set<string> data;
    rep(i, N){
        string temp; cin >> temp;
        string reverseTemp = temp;
        reverse(reverseTemp.begin(), reverseTemp.end());
        if(data.find(temp) == data.end() && data.find(reverseTemp) == data.end()) data.insert(temp);
    }
    cout << data.size() << endl;

    return 0;
}