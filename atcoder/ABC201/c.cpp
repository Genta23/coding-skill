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
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    string s; cin >> s;
    vector<int> in, not_in;
    rep(i, 10){
        if(s[i] == 'o') in.push_back(i);
        else if(s[i] == 'x') not_in.push_back(i);
    }
 
    int cnt = 0;
    rep(i, 10){
        rep(j, 10){
            rep(k, 10){
                rep(l, 10){
                    //この文字は含まれてますか??
                    bool flag = true;
                    int in_size = in.size();
                    rep(m, in_size){
                        int n = in[m];
                        if(n==i || n==j || n==k || n==l){
                            ;
                        }
                        else flag = false;
                    }

                    //この文字は含まれてませんよね??
                    int not_in_size = not_in.size();
                    rep(m, not_in_size){
                        int n = not_in[m];
                        if(n!=i && n!=j && n!=k && n!=l){
                            ;
                        }
                        else flag = false;
                    }
                    
                    if(flag) cnt++;
                }
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}