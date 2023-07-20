#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N;
    string S, T;
    cin >> N >> S >> T;

    for(int i=0; i<N; i++){
        if(S[i] == T[i]){
            ;
        }
        else if(S[i] == '1' && T[i] == 'l'){
            ;
        }
        else if(S[i] == 'l' && T[i] == '1'){
            ;  
        }
        else if(S[i] == '0' && T[i] == 'o'){
            ;   
        }
        else if(S[i] == 'o' && T[i] == '0'){
            ;   
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}