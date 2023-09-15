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

class UnionFind{
public:
    UnionFind() = default;
    
    explicit UnionFind(size_t n) : m_parents(n), m_sizes(n, 1){
		iota(m_parents.begin(), m_parents.end(), 0);
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

int main(){
    int n; cin >> n;
    UnionFind uf(202020);

    vector<int> data;
    rep(i, n){
        int tmp; cin >> tmp;
        data.push_back(tmp);
    }

    // 探索は半分までで良い nが奇数の時
    rep(i, n/2){
        uf.merge(data[i], data[n-1-i]);
    }

    int ans = 0;
    // それが根なら加算する
    rep(i, 202020) if(uf.find(i) == i) ans += uf.size(i)-1;

    cout << ans << endl;    
    return 0;
}