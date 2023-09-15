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

struct Data{
    int x, y;
};

bool operator<(const Data &a, const Data &b){//constつけないとダメだったはず
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
    }

int main(){
    int n; cin >> n;
    string s; cin >> s; //順序をつけるから比較関数の変更を行う必要がある
    
    set<Data> pos;
    Data p = {0, 0};
    pos.insert(p);
    rep(i, n){
        if(s[i] == 'U') p.y++;
        else if(s[i] == 'R') p.x++;
        else if(s[i] == 'D') p.y--;
        else if(s[i] == 'L') p.x--;
        pos.insert(p);
    }

    //posの中身を見る
    /*for (auto i : pos) {
        cout << i.x << ", " << i.y << endl;
    }*/

    if(pos.size() != n+1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}