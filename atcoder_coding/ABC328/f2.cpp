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

    explicit UnionFind(size_t n) : m_parents(n), m_sizes(n, 1), m_weights(n){
        iota(m_parents.begin(), m_parents.end(), 0);
    }

    int find(int i){ // 再帰関数でルートを特定
        if(m_parents[i] == i) return i;
		int par = find(m_parents[i]);
		m_weights[i] += m_weights[m_parents[i]]; // 累積和
        return (m_parents[i] = par); // 経路圧縮
    }

    void merge(int a, int b, ll c){
        int root_a = find(a); int root_b = find(b); // ルートを取得 // ここの更新が悪さをしている
        if(root_a != root_b){ // swap周りが怪しいような でもswapを禁止してもうまく行くわけではない
            if(m_sizes[root_a] < m_sizes[root_b]) swap(root_a, root_b), swap(a, b), c = -c; // swap(a, b)ではポインタの交換が行われている
            m_sizes[root_a] += m_sizes[root_b]; // 全てのサイズを変更していると計算時間が増大するので、ルートの情報のみを書き換える
            m_weights[b] = m_weights[a] + c;
            m_parents[root_b] = root_a; // ルートの情報を書き換える
        }
    }

    bool connected(int a, int b) { return (find(a) == find(b)); }

    int size(int i) { return m_sizes[find(i)]; }

    ll weight(int x) { find(x); return m_weights[x]; }

    ll diff(int x, int y) { return weight(x) - weight(y); }

    void pri(int time) { 
        cout << time << " : " << endl;;
        rep(i, 20) cout << m_parents[i] << " ";
        cout << endl;
        rep(i, 20) cout << m_weights[i] << " ";
        cout << endl;
    }

private:
    vector<int> m_parents, m_sizes;
	vector<ll> m_weights;
};

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(q), b(q);
    vector<ll> d(q);
    rep(i, q){
        int tmp1, tmp2; ll tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        tmp1--, tmp2--;
        a[i] = tmp1, b[i] = tmp2, d[i] = tmp3;
    }

    UnionFind uf(n); //ufのインスタンスを生成
    vector<int> ans;
    rep(i, q){
        uf.pri(i+1);
        if(!uf.connected(a[i], b[i])){
            uf.merge(a[i], b[i], -d[i]); // a[i]からみてb[i]はどのような重さか ここの部分が感覚的ではないかもしれないため少し考えてみる
            //cout << i+1 << " ";
            ans.push_back(i+1);
        }
        else{
            if(uf.diff(a[i], b[i]) == d[i]) ans.push_back(i+1); //cout << i+1 << " "; // a[i] - b[i]なので、b[i]からみてどのような重さかということになる
        }
        uf.pri(i+1);
    }
    
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;

    /*//使用方法を少しだけ明記しておく
    int i, j; ll k;
    uf.find(i); // rootが返ってくる
    uf.merge(i, j, k); // グループ化をするmerge //kに関しての話をもう少し考察してみる 今回の問題ではd(c)を反転しているから問題が起きないのかx
    uf.connected(i, j); // 戻り値はtrue, false
    uf.size(i); // その要素が所属するグループの要素数を求める
    uf.weight(i); // ルートからの重みを返す
    uf.diff(i, j); // i, jの重みの違いを表現する*/

    return 0;
}