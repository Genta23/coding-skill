#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string s; cin >> s;
  int n = (int)s.size();
  vector<vector<long long>> ans(n, vector<long long>(4));
  vector<bool> data(n);
  for(int i=0; i<n; i++){
    if(s[i] == 'o') data[i] = false;
    else data[i] = true;
  }

  // oo, xo, ox, xx
  if(data[0] && data[1]){ // xx
    ans[1][0] = 1LL, ans[1][1] = 1LL, ans[1][2] = 1LL, ans[1][3] = 1LL;
  }
  else if(data[0] && !data[1]){ // xo
    //ans[1][0] = 1LL, ans[1][2] = 1LL; // ミス
    ans[1][0] = 1LL, ans[1][1] = 1LL;
  }
  else if(!data[0] && data[1]){
    //ans[1][0] = 1LL, ans[1][1] = 1LL; // ミス
    ans[1][0] = 1LL, ans[1][2] = 1LL;
  }
  else if(!data[0] && !data[1]){
    ans[1][0] = 1LL;
  }

  // oo, xo, ox, xx
  // x, o
  for(int i=2; i<n; i++){
    if(data[i]){
      ans[i][0] = ans[i-1][0] + ans[i-1][1];
      ans[i][1] = ans[i-1][2] + ans[i-1][3];
      ans[i][2] = ans[i-1][0] + ans[i-1][1];
      ans[i][3] = ans[i-1][2];  //+ ans[i-1][3];
    }
    else if(!data[i]){
        ans[i][0] = ans[i-1][0] + ans[i-1][1];
        ans[i][1] = ans[i-1][2] + ans[i-1][3];
    }
  }
  cout << ans[n-1][0] + ans[n-1][1] + ans[n-1][2] + ans[n-1][3] << endl;
  for(int i=0; i<n; i++){
    cout << (data[i] ? 'x' : 'o') << " ";
    for(int j=0; j<4; j++){
        cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
