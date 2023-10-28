#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
struct Graph{
    int edge;
    int next;

};
int calculateDistance(string a, string b){
    int size = a.size();
    int distance = 0;
    rep(i,size){
        if(a[i] != b[i]){//このカウントの方法に問題がある... -> 1箇所の置換なので2ではなく1
            distance++;
        }
    }
    return distance;
}
bool search(vector<vector<Graph>> e, int s, vector<bool> f, int count){
    count++;
    if(f[s] == true) return false;
    if(count == f.size()) return true;
    int size = e[s].size();
    f[s] = true;
    rep(i, size){
        if(search(e, e[s][i].next, f, count)){
            return true;
        }
    }
    return false;
}
int main(){
    int N, M; cin >> N >> M;
    vector<string> data;
    rep(i,N){
        string temp; cin >> temp;
        data.push_back(temp);
    }
    int distanceMatrix[N][N];
    rep(i,N){
        rep(j,N){
            distanceMatrix[i][j] = calculateDistance(data[i], data[j]);
        }
    }
    /* グラフの作成 */
    vector<vector<Graph>> e;
    rep(i,N){
        vector<Graph> ei;
        rep(j,N){
            if(distanceMatrix[i][j] == 1){
                Graph temp;
                temp.edge = i;
                temp.next = j;
                ei.push_back(temp);
            }
        }
        e.push_back(ei);
    }
    /* 探索 */
    vector<bool> flag(N);
    rep(i,N){
        if(search(e, i, flag, 0)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
/* 35'26" */