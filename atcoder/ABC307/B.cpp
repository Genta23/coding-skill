#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N;
    cin >> N;

    string str[N];
    rep(i, N){
        cin >> str[i];
    }

    int count=0;
    rep(i, N){
        rep(j, N){
            if(i != j){
                string temp = str[i] + str[j];
                bool flag = true;
                rep(k, temp.length()){
                    if(temp[k] != temp[temp.length()-1-k]){
                        flag = false;
                    }
                }
                if(flag){
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}