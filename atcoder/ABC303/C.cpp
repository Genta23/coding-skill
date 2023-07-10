#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
struct Data{
    int x, y;
};
bool operator<(const Data &a, const Data &b) {
    if(a.x != b.x){
        return a.x < b.x;
    }
    else{
        return a.y < b.y;
    }
}
int main(){
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    
    string S;
    cin >> S;

    map<Data, bool> life;
    rep(i,M){
        Data temp;
        cin >> temp.x >> temp.y;
        life[temp] = true;
    }

    Data position = {0, 0};
    int str_size = S.length();
    rep(i,str_size){
        H--;
        if(H < 0){
            cout << "No" << endl;
            return 0;
        }

        if(S[i] == 'R'){
            position.x++;
        }
        if(S[i] == 'L'){
            position.x--;
        }
        if(S[i] == 'U'){
            position.y++;
        }
        if(S[i] == 'D'){
            position.y--;
        }

        if(life[position]){
            if(H<K){
                H = K;
                life[position] = false;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}