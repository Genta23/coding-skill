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

int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(q), b(q), d(q);

    rep(i, q){
        ll tmp1, tmp2, tmp3; cin >> tmp1 >> tmp2 >> tmp3;
        tmp1--, tmp2--;
        a[i] = tmp1, b[i] = tmp2, d[i] = tmp3;
    }

    UnionFind uf(n);

    Graph g(n);
    rep(i, q){
        if(!uf.connected(a[i], b[i])){
            g[a[i]].push_back(Edge(b[i], -d[i]));
            g[b[i]].push_back(Edge(a[i], d[i]));
        }
        uf.merge(a[i], b[i]);
    }

    vector<ll> dis(n);
    vector<bool> flag(n);
    rep(i, n){
        if(!flag[i]){
            queue<int> que;
            flag[i] = true;
            que.push(i);
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(auto x : g[v]){
                    if(flag[x.to]) continue;
                    flag[x.to] = true;
                    dis[x.to] = dis[v] + x.weight;
                    que.push(x.to);
                }
            }
        }
    }

    vector<int> ans;
    rep(i, q) if((dis[a[i]] - dis[b[i]]) == d[i]) ans.push_back(i+1);

    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
    return 0;
}