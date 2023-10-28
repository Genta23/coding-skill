#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N;
    cin >> N;
    
    vector<string> data;
    rep(i, N){
        string temp;
        cin >> temp;
        data.push_back(temp);
    }

    rep(i, N){
        if(i == 0){
            cout << data[1].substr(0, 1) << data[0].substr(0, N-1) << endl;
        }
        else if(i == N-1){
            cout << data[N-1].substr(1, N-1) << data[N-2].substr(N-1, 1) << endl;
        }
        else{
            cout << data[i+1].substr(0, 1) << data[i].substr(1, N-2) << data[i-1].substr(N-1, 1) << endl;
        }
    }
}
/*int main(){
    int N;
    cin >> N;
    vector<vector<int>> data(N, vector<int>(N));

    rep(i, N){
        rep(j, N){
            int temp;
            cin >> temp;
            if(i == 0 && j != N-1){
                data.at(i).at(j+1) = temp;
            }
            else if(j == N-1 && i != N-1){
                data.at(i+1).at(j) = temp;
            }
            else if(i == N-1 && j != 0){
                data.at(i).at(j-1) = temp;
            }
            else if(j == 0 && i != 0){
                data.at(i-1).at(j) = temp;
            }
            else{
                data.at(i).at(j) = temp;
            }
        }
    }

    rep(i, N){
        rep(j, N){
            cout << data.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}*/