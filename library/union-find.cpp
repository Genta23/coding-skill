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

    int find(int i){ // 再帰関数でルートを特定
        if(m_parents[i] == i) return i;
        return (m_parents[i] = find(m_parents[i])); // 経路圧縮
    }

    void merge(int a, int b){
        a = find(a); b = find(b); // ルートを取得
        if(a != b){
            if(m_sizes[a] < m_sizes[b]) swap(a, b); // swap(a, b)ではポインタの交換が行われている
            m_sizes[a] += m_sizes[b]; // 全てのサイズを変更していると計算時間が増大するので、ルートの情報のみを書き換える
            m_parents[b] = a; // ルートの情報を書き換える
        }
    }

    bool connected(int a, int b) { return (find(a) == find(b)); }

    int size(int i) { return m_sizes[find(i)]; }

private:
    vector<int> m_parents, m_sizes;
};
//find(i) iのrootを見つける
//merge(i, j) iのグループとjのグループを統合する
//connected(i, j) 同じグループか判定する
//size(i) 同じグループに属する要素数を返す
int main(){
    int N; cin >> N;
    UnionFind uf(N); //ufのインスタンスを生成

    //使用方法を少しだけ明記しておく
    int i, j;
    uf.find(i); // rootが返ってくる
    uf.merge(i, j); // グループ化をするmerge
    uf.connected(i, j); // 戻り値はtrue, false
    uf.size(i); // その要素が所属するグループの要素数を求める
    
    return 0;
}