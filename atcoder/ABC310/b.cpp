#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
struct Data{
    int p;
    int c;
    vector<int> f;
};
/* 入力したベクターの包含関係を調査するモジュール */
bool checkSuperVector(vector<int> a, vector<int> b){
    int ite = 0;
    rep(i, a.size()){
        while(1){
            if(ite == b.size()){
                return false;
            }
            if(a[i] == b[ite]){
                break;
            }
            else{//ここ本当はelseいらない
                ite++;
            }
        }
    }
    return true;
}
int main(){
    int N, M; cin >> N >> M;
    vector<Data> data;
    rep(i, N){
        Data dtemp;
        cin >> dtemp.p >> dtemp.c;
        rep(j, dtemp.c){
            int temp; cin >> temp;
            dtemp.f.push_back(temp);
        }
        sort(dtemp.f.begin(), dtemp.f.end());
        data.push_back(dtemp);
    }

    rep(i, N){
        rep(j, N){
            if(checkSuperVector(data[i].f, data[j].f)){//i 小 j 大
                /* この時点で機能の包含関係にフィルタリングができる */
                if(data[i].p > data[j].p){
                    cout << "Yes" << endl;
                    return 0;
                }
                else if(data[i].p == data[j].p && data[i].f.size() < data[j].f.size()){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}