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
    int flag = 0;
    rep(i, N){
        if(ans.length() == 0){
            ans = str[i];
        }
        else{
            ans += str[i];
        }

        if(str[i] == '('){
            flag++;
        }
        else if(str[i] == ')'){
            while(flag != 0){
                ans.erase(ans.length()-1);
                if(ans[ans.length()-1] == '('){
                    flag--;
                    ans.erase(ans.length()-1);
                    break;//breakがないと0になるまで消し続ける地獄が発生する
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}