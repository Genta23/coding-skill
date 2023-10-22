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
typedef long long ll;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    cout << (7&((1<<2)|(1<<0))) << endl;

    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //配列はできないのか
    auto itr = lower_bound(data.begin(), data.end(), 9);
    int d = distance(data.begin(), itr);
    cout << d << endl;

    itr = upper_bound(data.begin(), data.end(), 9);
    d = distance(data.begin(), itr);
    cout << d << endl;

    map<int, int> a;
    a[1]++;
    a[2]--;
    a[2]++;
    for (const auto& [k, v] : a) {
        cout << k << " " << v << endl;
    }
    cout << a.begin()->second << endl;
    cout << a.rbegin()->second << endl;
    return 0;
}