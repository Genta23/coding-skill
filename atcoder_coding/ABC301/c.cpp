#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int vector_finder(std::vector<int> vec, int number) { //https://qiita.com/wonder_zone/items/51fb5c3a773b98aa130c
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main(){
    /* 2個の文字列のを分解して同じであれば良いということ @ワイルドカードの扱いを考える */
    /* 26+1文字がくるということなので、27サイズの配列を使用してみる */
    /* 対称性がある */
    string s, t; cin >> s >> t;
    vector<int> s_data(27), t_data(27), data(27); //vectorの場合は0で初期化されている
    int size = s.size(); //サイズの部分は待避した方が良さそう コンパイルエラーを防げる
    rep(i, size){
        if(int(s[i]) == 64){
            s_data[26]++;
        }
        else{
            s_data[int(s[i]) - 97]++;
        }
        if(int(t[i]) == 64){
            t_data[26]++;
        }
        else{
            t_data[int(t[i]) - 97]++;
        }
    }
    vector<int> flag{0, 2, 3, 4, 14, 17, 19};
    int s_count = 0, t_count = 0;
    rep(i, 26){
        data[i] = s_data[i] - t_data[i];
        if(vector_finder(flag, i)){
            if(data[i] > 0){
                s_count += data[i];
            }
            if(data[i] < 0){
                t_count -= data[i];
            }
        }
        else{
            if(data[i] != 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if(t_count <= s_data[26] && s_count <= t_data[26]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
/* 29'47" */