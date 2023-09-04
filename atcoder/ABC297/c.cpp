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

int main(){
    int h, w; cin >> h >> w;
    
    vector<string> s;
    rep(i, h){
        string temp; cin >> temp;
        s.push_back(temp);
    }

    int cnt = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == 'T' && s[i][j+1] == 'T'){
                s[i][j] = 'P', s[i][j+1] = 'C';
                cnt++;
            }
        }
    }
    
    rep(i, h){
        cout << s[i] << endl;
    }
    return 0;
}