#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main() {
    int n, m; cin >> n >> m;

    // グラフ
    Graph g(N);
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        g[from].push_back(Edge(to, weight));
    }
}

/*
Edge(int t, int w) : to(t), weight(w) { }
このように書くことで、

Edge e;
e.to = _;
e.weight = _;
と書いていたものを

Edge(to, weight);
*/
