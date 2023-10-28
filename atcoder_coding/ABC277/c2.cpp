#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int check(int p, map<int, int> t, vector<vector<int>> data, vector<bool>& flag){ //vectorは値渡しが行われる
    if(flag[t[p]]) return 0;
    flag[t[p]] = true;
  
    rep(i, data[t[p]].size()){
        //if(!flag[t[data[t[p]][i]]]) check(data[t[p]][i], t, data, flag);
        check(data[t[p]][i], t, data, flag);
    }
    return 0;
}

int main(){
    int n; cin >> n;

    map<int, int> t; //頂点番号を入力するとインデックスを返す
    map<int, int> inv_t; //インデックスを入力すると頂点番号を返す
    vector<vector<int>> data(2*n); //頂点は高々2n

    int index = 0;
    bool f = false;
    rep(i, n){
        int a, b; cin >> a >> b;
        if(t.find(a) == t.end()){
            inv_t[index] = a;
            t[a] = index++; //まだインデックスの登録をしていない場合
        }
        if(t.find(b) == t.end()){
            inv_t[index] = b;
            t[b] = index++;
        }
        data[t[a]].push_back(b);
        data[t[b]].push_back(a);

        if(a == 1 || b == 1) f = true;
    }
    
    if(!f){
        cout << 1 << endl;
        return 0;
    }

    vector<bool> flag(index);
    check(1, t, data, flag);

    int max = 0;
    rep(i, index){
        if(flag[i]){
            if(max < inv_t[i]) max = inv_t[i];
        }
    }

    cout << max << endl;
    return 0;
}