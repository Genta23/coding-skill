#include <bits/stdc++.h>
using namespace std;

vector<pair<char,long long>> runlength(string s) {
    int cnt = 1;
    char tmp = s[0];
    vector<pair<char, long long>> data;
    for(int i=1; i<s.size(); i++){
      if(s[i] == tmp) cnt++;
      else{
      data.push_back({tmp, cnt});
      tmp = s[i];
      cnt = 1;
     }
    }
    data.push_back({tmp, cnt});
    return data;
}

int main() {
    string s; cin >> s;
    auto rl=runlength(s);
    vector<long long> tri(63,0);
    tri[2]=1;
    for(int i=3;i<=63;i++) tri[i]+=tri[i-1]+tri[i-2]+tri[i-3];
    long long ans=1;
    for(auto u:rl) {
        if(u.first == 'x') ans*=tri[u.second+3];
    }
    cout << ans << endl;
    return 0;
}