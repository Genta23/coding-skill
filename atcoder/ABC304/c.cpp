#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
#define repBeginEnd(i, begin, end) for (int i=begin; i<=end; i++)
#define distance(x1, x2, y1, y2) (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)
/* 構造体書きづらいからあんまりやなあ */
struct Data{
    int x, y, tag;
};
int main(){
    int n, d;
    cin >> n >> d;

    vector<Data> data(n);
    int tagCount = 0;
    rep(i,n){
        cin >> data[i].x >> data[i].y;
        set<int> value;
        rep(j,i){
            if(distance(data[i].x, data[j].x, data[i].y, data[j].y) <= d*d){
                value.insert(data[j].tag);
            }
        }
        //sort(value.begin(), value.end());
        if(value.size() != 0){
            data[i].tag = *value.begin(); //begin()はイテレータを指すので、その要素の値が欲しい場合*を利用する
        }
        else{
            data[i].tag = tagCount;
            tagCount++;
        }
        rep(j,i){
            if(find(value.begin(), value.end(), data[j].tag) != value.end()){
                data[j].tag = *value.begin();
            }
        }
    }
    rep(i,n) cout << ((data[i].tag == 0) ? "Yes" : "No") << endl;
    return 0;
}