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
#include <numeric> // std::iota()
#include <utility> // std::swap()
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

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

int main(){
    int n; cin >> n;
    UnionFind uf(n); //ufのインスタンスを生成

    ll ans = 0;
    min_priority_queue<tuple<int, int, int>> que;

    rep(i, n-1){//グラフ系は受け取ったときに減算しましょうか
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        que.push({w, u, v}); // 重みが最大優先事項
    }

    /*rep(i, n-1){
        auto v = que.top(); que.pop();
        cout << get<0>(v) << " " << get<1>(v) << " " << get<2>(v) << endl;
    }*/

    while(!que.empty()){
        auto x = que.top(); que.pop();
        int w = get<0>(x), u = get<1>(x), v = get<2>(x);

        ans += (ll) w * uf.size(u) * uf.size(v);
        uf.merge(u, v);
    }

    //使用方法を少しだけ明記しておく
    /*int i, j;
    uf.find(i); // rootが返ってくる
    uf.merge(i, j); // グループ化をするmerge
    uf.connected(i, j); // 戻り値はtrue, false
    uf.size(i); // その要素が所属するグループの要素数を求める*/

    cout << ans << endl;
    return 0;
}