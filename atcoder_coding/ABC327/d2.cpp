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

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i];
    rep(i, m) cin >> b[i];

    vector<pair<int, int>> data;
    rep(i, m){
        int p = a[i], q = b[i];
        data.push_back({a[i], b[i]});
        data.push_back({b[i], a[i]});
    }

    sort(data.begin(), data.end());

    UnionFind uf(200007);

    rep(i, data.size()-1){
        if(data[i].first == data[i+1].first){
            uf.merge(data[i].second, data[i+1].second);
        }
    }

    rep(i, m){
        if(uf.connected(a[i], b[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}