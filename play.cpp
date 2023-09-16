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
    map<int, string> data{
        {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}
    };

    for (const auto& [k, v] : data) {
        cout << k << " " << v << endl;
    }
    return 0;
}