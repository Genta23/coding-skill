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

int main(){
    char p, q; cin >> p >> q;
    int dis[7] = {0, 3, 4, 8, 9, 14, 23};
    cout << abs(dis[int(q)-65] - dis[int(p)-65]) << endl; //p - 'A'十分なのです
    return 0;
}
/* 5'24" */