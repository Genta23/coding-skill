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
    cout << s << endl;
    long long power = 1;
    long long num = 0;
    rep(i,s.size()){
        num += (s[s.size()-1-i]-'0') * power; //intのキャストの部分でミスがあった (int)s[s.size()-1-i]としているのが原因
        power *= 2;
    }
    return num;
}
void replaceCharacter(string& str, char target, char replacement) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == target) {
            str[i] = replacement;
        }
    }
}
int main(){
    string s; long long n; cin >> s >> n;
    string data = makeBit(n);
    cout << makeBit(n) << endl;
    cout << s.size() << endl;
    cout << data << endl;
    if(s.size() < data.size()){
        replaceCharacter(s, '?', '1');
    }
    else if(s[s.size() - data.size()] == '0' || '?'){
        int ite = 0;
        while(s.size() - data.size() - ite > 0){ //>= ??
            if(s[s.size() - data.size() - ite] == '1'){
                cout << -1 << endl;
                return 0;
            }
            if(s[s.size() - data.size() - ite] == '?'){
                s[s.size() - data.size() - ite] = '0';
            }
            ite++;
        }
        ite = 0;
        while(s.size() - data.size() + ite < s.size()){
            if(s[s.size() - data.size() + ite] == '?'){
                s[s.size() - data.size() + ite] = '1';
            }
            ite++;
        }
    }
    else{ // s[s.size() - data.size()] = '0'
        int ite = 0;
        while(s.size() - data.size() - ite > 0){ //>= ??
            if(s[s.size() - data.size() - ite] == '1'){
                cout << -1 << endl;
                return 0;
            }
            if(s[s.size() - data.size() - ite] == '?'){
                s[s.size() - data.size() - ite] = '0';
            }
            ite++;
        }
        ite = 0;
        bool flag = false;
        while(s.size() - data.size() + ite < s.size()){
            if(flag){
                if(s[s.size() - data.size() - ite] == '?'){
                    s[s.size() - data.size() - ite] = '0';
                }
            }
            if(data[ite] == '1' && s[s.size() - data.size() + ite] == '?'){
                s[s.size() - data.size() + ite] = '1';
            }
            else if(data[ite] == '0' && s[s.size() - data.size() + ite] == '?'){
                s[s.size() - data.size() + ite] = '1';
            }
            else if(data[ite] == '0' && s[s.size() - data.size() + ite] == '1'){
                cout << -1 << endl;
                return 0;
            }
            else if(data[ite] == '1' && s[s.size() - data.size() + ite] == '0'){
                flag = true;
            }
            ite++;
            // 1,1 0,0はスルー
        }
    }
    cout << convertBit(s) << endl;

    return 0;
}