#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
int main(){
    int N;
    cin >> N;

    string str;
    cin >> str;
    
    string ans;
    bool flag = false;//flagで管理すると2個以上ある時に以上が生じる
    rep(i, N){
        if(ans.length() == 0){
            ans = str[i];
        }
        else{
            ans += str[i];
        }

        if(str[i] == '('){
            flag = true;
        }
        else if(str[i] == ')'){
            while(flag){
                ans.erase(ans.length()-1);
                if(ans[ans.length()-1] == '('){
                    flag = false;
                    ans.erase(ans.length()-1);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}