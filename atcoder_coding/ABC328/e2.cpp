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
struct Edge {
    ll to;     // 辺の行き先
    ll weight; // 辺の重み
    Edge(ll t, ll w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

class UnionFind{
public:
    UnionFind() = default;
    
    explicit UnionFind(size_t n) : m_parents(n), m_sizes(n, 1){
		std::iota(m_parents.begin(), m_parents.end(), 0);
	}

	int find(int i){
		if (m_parents[i] == i) return i;

		// 経路圧縮
		return (m_parents[i] = find(m_parents[i]));
	}

	void merge(int a, int b){
		a = find(a);
		b = find(b);

		if (a != b){
			// union by size (小さいほうが子になる）
			if (m_sizes[a] < m_sizes[b]) swap(a, b);

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
		}
	}

	bool connected(int a, int b) { // これ条件分岐ではなく、関数だから{ }省略できない
        return (find(a) == find(b));
    }

	int size(int i){
        return m_sizes[find(i)]; 
    }

private:
    vector<int> m_parents;
    vector<int> m_sizes;
};
//find(i) iのrootを見つける
//merge(i, j) iのグループとjのグループを統合する
//connected(i, j) 同じグループか判定する
//size(i) 同じグループに属する要素数を返す

/*int main(){
    int N; cin >> N;
    UnionFind uf(N); //ufのインスタンスを生成

    //使用方法を少しだけ明記しておく
    int i, j;
    uf.find(i); // rootが返ってくる
    uf.merge(i, j); // グループ化をするmerge
    uf.connected(i, j); // 戻り値はtrue, false
    uf.size(i); // その要素が所属するグループの要素数を求める
    
    return 0;
}*/

int main() {
    int n, m; ll k; cin >> n >> m >> k;
    vector<ll> u(m), v(m), w(m);
    rep(i, m) cin >> u[i] >> v[i] >> w[i];
    rep(i, m) u[i]--, v[i]--;
    vector<bool> f(m);
    rep(i, n-1) f[i] = true;
    sort(f.begin(), f.end());
    ll min = infl;
    do{
        UnionFind uf(n); //UnionFind 0start
        ll sum = 0;
        rep(i, m){
            if(f[i]){
                uf.merge(u[i], v[i]);
                sum += w[i];
                sum %= k;
            }
        }
        if(uf.size(1) == n) chmin(min, sum);
    }while(next_permutation(f.begin(), f.end()));
    cout << min << endl;
    return 0;
}