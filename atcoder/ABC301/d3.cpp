#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
string makeBit(long long n){ //ここがintになっていた
    string str = "";
    while(n>0){
        str += to_string(n%2);
        n = n/2;
    }
    reverse(str.begin(), str.end());
    return str;
} 
long long convertBit(string s){
    long long power = 1;
    long long num = 0;
    long long size = s.size();
    for(int i=0; i<size; i++){
        num += (s[s.size()-1-i]-'0') * power; //intのキャストの部分でミスがあった (int)s[s.size()-1-i]としているのが原因
        power *= 2;
    }
    return num;
}
void replaceCharacter(string& str, char target, char replacement) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == target) {
            str[i] = replacement;
        }
    }
}
bool makechar(string& s, string& data, char firstStr){
    long long ite = 0;
    bool flag = false;
    while(data.size() - ite > 0){ //ata.size()-1 - ite >=0 >= にすると無限ループに入る 理由は unsignedとか??
        if(flag){
            if(s[data.size()-1 - ite] == '?'){
                s[data.size()-1 - ite] = '1';
            }
        }
        else if(firstStr == '0'){
            if(s[data.size()-1 - ite] == '?'){
                s[data.size()-1 - ite] = '1';
            }
        }
        else if(firstStr == '1'){
            if(data[data.size()-1 - ite] == '0' && s[data.size()-1 - ite] == '1'){
                return false;
            }
            else if(data[data.size()-1 - ite] == '1' && s[data.size()-1 - ite] == '0'){
                flag = true;
             }
            else{
                s[data.size()-1 - ite] = data[data.size()-1 - ite];
            }
        }
        ite++;
    }
    return true;
}
int main(){
    string s; long long n; cin >> s >> n;
    string data = makeBit(n);
    if(s.size() < data.size()){
        replaceCharacter(s, '?', '1');
    }
    else{
        reverse(s.begin(), s.end());
        reverse(data.begin(), data.end());
        //UP 0Padding -> d2で十分実装ができていた部分
        long long ite = 0;
        while(data.size() + ite < s.size()){
            if(s[data.size() + ite] == '1'){
                cout << -1 << endl;
                return 0;
            }
            if(s[data.size() + ite] == '?'){
                s[data.size() + ite] = '0';
            }
            ite++;
        }
        //Down hard
        ite = 0;
        char flagChar = s[data.size()-1];
        if(flagChar == '?'){
            string s_copy = s;
            if(makechar(s_copy, data, '1')){
                s = s_copy;
            }
            else{
                makechar(s, data, '0');
            }
        }
        else{
            if(!makechar(s, data, flagChar)){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    reverse(s.begin(), s.end());
    cout << convertBit(s) << endl;

    return 0;
    //今のアルゴリズムの問題点 1の上に?があってダメだった時にやり直しが効いていないような気がする
    //?100000 -> 110000としてドボンになっている 0を立てれば何があっても行けるから
    //1010101
}
/* 110 図を書いてちゃんと書くことにする そんなに難しい問題ではないと思うが 細部でミスが起きている */