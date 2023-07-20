#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;

    int data[M][N], table[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            table[i][j] = 0;
            if(i == j){
                table[i][j] = 1;
            }
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> data[i][j];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=1; j<N; j++){
            table[data[i][j]-1][data[i][j-1]-1] = 1;
            table[data[i][j-1]-1][data[i][j]-1] = 1;
        }
    }

    int count=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(table[i][j] == 0){
                count++;
            }
        }
    }
    cout << count/2 << endl;
    return 0;
}