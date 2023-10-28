#include <iostream>
#include <vector>
using namespace std;

// 素因数分解
// 460 = 2^2 x 5 x 23 の場合
// 返り値は {{2, 2}, {5, 1}, {23, 1}}
vector<pair<long long, long long>> prime_factorize(long long N) {
    // 答えを表す可変長配列
    vector<pair<long long, long long>> res;

    // √N まで試し割っていく
    for (long long p = 2; p * p <= N; ++p) {
        // N が p で割り切れないならばスキップ
        if (N % p != 0) {
            continue;
        }

        // N の素因数 p に対する指数を求める
        int e = 0;
        while (N % p == 0) {
            // 指数を 1 増やす
            ++e;

            // N を p で割る
            N /= p;
        }

        // 答えに追加
        res.emplace_back(p, e);
    }

    // 素数が最後に残ることがありうる
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}

int main() {
    int n; cin >> n;

    int count = 0;
    for(int i=1; i<n; i++){
        int N = i;
        vector<pair<long long, long long>> pf = prime_factorize(N);

        bool flag = false;
        if(pf.size() == 3){
            if(pf[0].second == 2 && pf[1].second == 1 && pf[2].second == 2){
                flag = true;
            }
        }
        if(flag) count++;
    }
    cout << count << endl;
    return 0;
}