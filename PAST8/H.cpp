#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

struct graph {
    /*
    to::ノードの接続(to.fi::接続先ノード, to.se::辺のid)
    eg::idをキーとした辺のハッシュマップ.valueは辺の長さ.
    */
    int size;
    vector<vector<P>> to;
    unordered_map<int, int> eg;
    
    graph(int N): size(N), to(vector<vector<P>>(N)) {}

    //ノードの接続.
    void connect(int id, int a, int b, int c) {
        to[a].eb(b, id);
        to[b].eb(a, id);
        eg[id] = c;
    }

    //特定頂点からのbfs.
    vector<int> bfs(int st) {
        vector<int> dist(size, -1);
        queue<int> q;
        dist[st] = 0;
        q.push(st);
        while (q.size()) {
            int v = q.front(); q.pop();
            //to[v]::vに接続された頂点,辺の情報.
            for (auto p: to[v]) {
                int nv, id; tie(nv, id) = p;
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + eg[id];
                q.push(nv);
            }
        }
        return dist;
    }
};

int main() {
    //入力.
    int N, X; cin >> N >> X;
    //グラフの形成.
    graph g(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        g.connect(i, a, b, c);
    }

    //全頂点を始点としてbfsを行い,条件を満たすか確かめる.
    for (int i = 0; i < N; ++i) {
        vector<int> res = g.bfs(i);
        for (int j = 0; j < N; ++j) {
            //発見したら終了.
            if (res[j] == X) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    //未発見だった場合.
    cout << "No" << endl;
    return 0;
}