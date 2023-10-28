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

void print(const vector<int>& v)
{
  for_each(v.begin(), v.end(), [](int x) {
    cout << x << " ";
  });
  cout << endl;
}

int main(){
    int h, w; cin >> h >> w;

    vector<vector<int>> data;
    rep(i, h){
        vector<int> t;
        rep(j, w){
            int temp; cin >> temp;
            t.push_back(temp);
        }
        data.push_back(t);
    }

    vector<int> v(w-1, 0);
    vector<int> d(h-1, 1);
    v.insert(v.end(), d.begin(), d.end()); // 0 : 右に移動 1 : 下に移動

    int cnt = 0;
    do {
        int vi = 0, vj = 0;
        set<int> num;
        num.insert(data[vi][vj]);
        rep(i, v.size()){
            if(v[i] == 0){
                vj++;
                num.insert(data[vi][vj]);
            }
            else if(v[i] == 1){
                vi++;
                num.insert(data[vi][vj]);
            }

            if(num.size() == v.size()+1){
                cnt++;
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << cnt << endl;
    return 0;
}