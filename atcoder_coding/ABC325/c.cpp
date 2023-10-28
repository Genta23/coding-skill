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

UnionFind uf(1000000);
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
    int h, w; cin >> h >> w;
    vector<string> data(h); rep(i, h) cin >> data[i];
    rep(i, h){
        rep(j, w){
            if(data[i][j] == '#'){
                if(j+1 < w){
                    if(data[i][j+1] == '#'){
                        uf.merge(i*w + j, i*w + j+1);
                    }                
                }
                if(i+1 < h && j+1 < w){
                    if(data[i+1][j+1] == '#'){
                        uf.merge(i*w + j, (i+1)*w + j+1);
                    }     
                }
                if(i+1 < h){
                    if(data[i+1][j] == '#'){
                        uf.merge(i*w + j, (i+1)*w + j);
                    }     
                }
                if(i+1 < h && j > 0){
                    if(data[i+1][j-1] == '#'){
                        uf.merge(i*w + j, (i+1)*w + j-1);
                    }     
                }
            }
        }
    }
    rep(i, h){
        rep(j, w){
            if(data[i][j] == '#'){
                if(j+1 < w){
                    if(data[i][j+1] == '#'){
                        uf.merge(i*w + j, i*w + j+1);
                    }                
                }
                if(i+1 < h && j+1 < w){
                    if(data[i+1][j+1] == '#'){
                        uf.merge(i*w + j, (i+1)*w + j+1);
                    }     
                }
                if(i+1 < h){
                    if(data[i+1][j] == '#'){
                        uf.merge(i*w + j, (i+1)*w + j);
                    }     
                }
                if(i+1 < h && j > 0){
                    if(data[i+1][j-1] == '#'){
                        uf.merge(i*w + j, (i+1)*w + j-1);
                    }     
                }
            }
        }
    }

    set<int> st;
    rep(i, h    ){
        rep(j, w){
            if(data[i][j] == '#'){
                st.insert(uf.find(i*w + j));
                cout << uf.find(i*w + j) << endl;
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}