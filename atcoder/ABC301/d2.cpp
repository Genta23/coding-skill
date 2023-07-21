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
int main(){
    string s; long long n; cin >> s >> n;
    string data = makeBit(n);
    if(s.size() < data.size()){
        replaceCharacter(s, '?', '1');
    }
    else{
        reverse(s.begin(), s.end());
        reverse(data.begin(), data.end());
        //UP 0Padding
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
        bool onBitFlag = false, flag = false;
        string s_copy = s;
        while(data.size() - ite > 0){ //ata.size()-1 - ite >=0 >= にすると無限ループに入る 理由は unsignedとか??
            if(s[data.size()-1] == '1'){
                if(flag){ //s[data.size()-1 - ite] == '?'忘れてた... //フラグ立ったら何もしないか0埋めるか
                    if(s[data.size()-1 - ite] == '?'){
                        s[data.size()-1 - ite] = '1';
                    }
                }
                else if(data[data.size()-1 - ite] == '1' && s[data.size()-1 - ite] == '?'){
                    if(data[data.size()-1] == '1' && s[data.size()-1] == '1'){
                        onBitFlag = true;
                    }
                    s[data.size()-1 - ite] = '1';
                }
                else if(data[data.size()-1 - ite] == '0' && s[data.size()-1 - ite] == '?'){
                    s[data.size()-1 - ite] = '0';
                }
                else if(data[data.size()-1 - ite] == '1' && s[data.size()-1 - ite] == '0'){
                    flag = true;
                }
                else if(data[data.size()-1 - ite] == '0' && s[data.size()-1 - ite] == '1'){
                    if(onBitFlag){
                        
                    }
                    cout << -1 << endl;
                    return 0;
                }
                // 11 00 は省略
                ite++;
            }
            else if(s[data.size()-1] == '0'){
                replaceCharacter(s, '?', '1');
            }
            else{
                if(data[data.size()-1 - ite] == '0' && s[data.size()-1 - ite] == '1'){
                    s[data.size()-1] = '0';
                    replaceCharacter(s, '?', '1');
                    return 0;
                }
            }
        }    
    }
    replaceCharacter(s, '?', '1');
    reverse(s.begin(), s.end());
    cout << convertBit(s) << endl;

    return 0;
    //今のアルゴリズムの問題点 1の上に?があってダメだった時にやり直しが効いていないような気がする
    //?100000 -> 110000としてドボンになっている 0を立てれば何があっても行けるから
    //1010101
}
/* 110 図を書いてちゃんと書くことにする そんなに難しい問題ではないと思うが 細部でミスが起きている */