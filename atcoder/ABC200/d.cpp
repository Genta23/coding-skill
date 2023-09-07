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
    int n; cin >> n;
    vector<int> data;
    vector<int> result(200);
    int size = min(n, 8);

    rep(i, size){ // n -> size にした もはや8個までしか格納する必要がないため
        int temp; cin >> temp;
        data.push_back(temp);
        //cin >> data[i]; //この2種類は異なるのと おそらくこれでエラーが出ているのは初期化を行なっていないからかな -> 否
        //あまり0のものが含まれている 0が挿入されているため気をつける必要がある
    }

    for (int tmp = 0; tmp < (1 << size); tmp++) {
        bitset<8> s(tmp);
        //long long r = 0;// ここがREの原因 intの最大値は2*1e9程度 しかし、複数足される場合があった そこでオーバーフローして配列外参照になった可能性がある...
        //CやC++では負の数のあまりは負の数で出力されるらしい...??
        int r = 0; //どうしてもintを使用したい場合余剰和に持ち込む方法もある 初期化忘れてたので実行のたびに解が変わった笑
        //今回みたいにWAではなくREになるの嫌やな
        rep(j, size){
            r += data[j]*s[j];
            r = r%200;//ここに1行追加してみる このように余剰によっての計算なら何とかなる
        }
        if(result[r%200] == 0){
            result[r%200] += tmp;
        }
        else{
            cout << "Yes" << endl;
            bitset<8> ans(result[r%200]);

            cout << ans.count() << " ";
            rep(i, size){
                if(ans[i]) cout << i+1 << " ";
            }
            cout << endl;

            cout << s.count() << " ";
            rep(i, size){
                if(s[i]) cout << i+1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

/*
for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
  bitset<ビット数> s(tmp);
  // (ビット列sに対する処理)
}
*/