#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
#include <bitset>
#include <tuple>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;

void swap_tate(vector<string>& data, int x, int y){
    string tmp = data[x];
    data[x] = data[y];
    data[y] = tmp;
}

void swap_yoko(vector<string>& data, int x, int y){
    vector<char> tmp;
    rep(i, data.size()) tmp.push_back(data[i][x]);

    rep(i, data.size()) data[i][x] = data[i][y];
    rep(i, data.size()) data[i][y] = tmp[i];
}

void print(vector<string> data){
    rep(i, data.size()){
        rep(j, data.size()){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void make_vector_front(string& data){
    vector<bool> flag(3);
    int n = data.size();
    rep(i, n){
        char tmp = data[i];
        if(tmp == 'A'){
            if(flag[0]) data[i] = '.';
            else flag[0] = true;
        }
        if(tmp == 'B'){
            if(flag[1]) data[i] = '.';
            else flag[1] = true;
        }
        if(tmp == 'C'){
            if(flag[2]) data[i] = '.';
            else flag[2] = true;
        }
    }
}

void make_vector_back(string& data){
    vector<bool> flag(3);
    int n = data.size();
    rep(i, n){
        char tmp = data[n-1 - i];
        if(tmp == 'A'){
            if(flag[0]) data[n-1 - i] = '.';
            else flag[0] = true;
        }
        if(tmp == 'B'){
            if(flag[1]) data[n-1 - i] = '.';
            else flag[1] = true;
        }
        if(tmp == 'C'){
            if(flag[2]) data[n-1 - i] = '.';
            else flag[2] = true;
        }
    }
}

int main(){
    int n; cin >> n;
    string r, c; cin >> r >> c;
    vector<string> data(n, "");
    rep(i, n){
        rep(j, n){ //i+jではなく(i+j)な
            if((i+j) % n == 0) data[i] += "A";
            if((i+j) % n == 1) data[i] += "B";
            if((i+j) % n == 2) data[i] += "C";
            if((i+j) % n == 3) data[i] += ".";
            if((i+j) % n == 4) data[i] += ".";
        }
    }

    string tmp_r = r, tmp_c = c;
    make_vector_back(tmp_r);
    make_vector_back(tmp_c);
    if(tmp_r[0] != '.' || tmp_c[0] != '.'){
        tmp_r = r, tmp_c = c;
        make_vector_front(tmp_r);
        make_vector_front(tmp_c);
    }
    r = tmp_r, c = tmp_c;

    int r_check = 0, c_check = 0;
    rep(i, n) if(r[i] != '.') r_check += (r[i] - 'A' + 1);
    rep(i, n) if(c[i] != '.') c_check += (c[i] - 'A' + 1);
    if(r_check != 6 || c_check != 6){
        cout << "No" << endl;
        return 0;
    }

    if(r[0] != c[0]){
        cout << "No" << endl;
        return 0;
    }
    
    vector<char> a{'A', 'B', 'C'};
    rep(i, 3){
        int x = 0, y = 0;
        rep(j, n){
            if(data[j][0] == a[i]) x = j;
            if(r[j] == a[i]) y = j;
        }
        swap_tate(data, x, y);
    }

    rep(i, 3){
        int x = 0, y = 0;
        rep(j, n){
            if(data[0][j] == a[i]) x = j;
            if(c[j] == a[i]) y = j;
        }
        swap_yoko(data, x, y);
    }

    cout << "Yes" << endl;
    for(string x : data) cout << x << endl;
    return 0;
}