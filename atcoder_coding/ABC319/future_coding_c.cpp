#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    if(s.size()%2 != 0) s += "o";

    vector<vector<long long>> ans(s.size()/2, vector<long long>(4)); // oo, ox, xo, xx
    if(s[0] == 'o' && s[1] == 'o') ans[0][0]++;
    else if(s[0] == 'o' && s[1] == 'x') ans[0][0]++, ans[0][1]++;
    else if(s[0] == 'x' && s[1] == 'o') ans[0][0]++, ans[0][2]++;
    else for(int i=0; i<4; i++) ans[0][i]++;
    
    for(int i=1; i<s.size()/2; i++){
        if(s[2*i] == 'o' && s[2*i+1] == 'o'){
            for(int j=0; j<4; j++) ans[i][0] += ans[i-1][j];
        }
        else if(s[2*i] == 'o' && s[2*i+1] == 'x'){
            for(int j=0; j<4; j++) ans[i][0] += ans[i-1][j];
            for(int j=0; j<4; j++) ans[i][1] += ans[i-1][j];
        }
        else if(s[2*i] == 'x' && s[2*i+1] == 'o'){
            for(int j=0; j<4; j++) ans[i][0] += ans[i-1][j];
            for(int j=0; j<3; j++) ans[i][2] += ans[i-1][j];
        }
        else{
            for(int j=0; j<4; j++) ans[i][0] += ans[i-1][j];
            for(int j=0; j<4; j++) ans[i][1] += ans[i-1][j];
            for(int j=0; j<3; j++) ans[i][2] += ans[i-1][j];
            ans[i][3] = ans[i-1][0] + ans[i-1][2];
        }
    }
    long long __ans = 0;
    for(int i=0; i<4; i++) __ans += ans[s.size()/2 - 1][i];
    cout << __ans << endl;
    return 0;
}
