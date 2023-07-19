#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int N, P, Q; cin >> N >> P >> Q;
    /* vector<int> price(N); で宣言してからpush_backするとN+1...となっていく*/
    vector<int> price;
    rep(i, N){
        int temp; cin >> temp;
        price.push_back(temp);
    }
    sort(price.begin(), price.end());
    cout << min(P, Q + price[0]) << endl;

    return 0;
}