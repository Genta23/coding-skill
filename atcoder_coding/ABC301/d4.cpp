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

int main(){
    string s; long long n; cin >> s >> n;
    string data = makeBit(n);
    vector<long long> queue;
    rep(i,s.size()){
        if(s[i] == '?'){
            s[i] = '0';
            queue.push_back(i);
        }
    }
    if(convertBit(s) > n){
        cout << -1 << endl;
        return 0;
    }
    rep(i,s.size()){
        if(find(queue.begin(), queue.end(), i) != queue.end()){
            s[i] = '1';
            if(convertBit(s) > n) s[i] = '0';
        }
    }
    cout << convertBit(s) << endl;
    return 0;
}
/* このアルゴリズムだとミスもなく早く解くことができた fin */