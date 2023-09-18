#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
#include <bitset>
using namespace std;
typedef long long ll;
const int inf = 1e9;
#define rep(i,n) for (int i=0; i<n; i++)

int cal(map<char, int> &data, int size){
    int p = 1;
    rep(i, size) p = p * (i+1);
    for(const auto& [k, v] : data){
        int c = v;
        rep(i, v){
            p = p/c;
            c--;
        }
    }
    return p;
}
int main(){
    //max 40320
    string s; cin >> s;
    int num; cin >> num;

    // こうゆうのは1文字目から順に決めていく
    map<char, int> data;
    rep(i, s.size()) data[s[i]]++;

    string ans;

    rep(i, s.size()){
        for(const auto& [k, v] : data){
            if(v == 0) continue;
            data[k]--;
            int temp = cal(data, s.size()-ans.size()-1);
            if(temp < num){
                num -= temp;
                data[k]++;
            }
            else{
                ans.push_back(k);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}