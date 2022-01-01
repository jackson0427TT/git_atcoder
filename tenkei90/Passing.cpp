#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, ll>;
const ll INF = 8e18;

//ダイクストラ用のグラフ.
struct graph {
    int size;
    vector<vector<P>> to;
    graph(int n): size(n), to(vector<vector<P>>(n)) {}

    //グラフ構築.
    void merge(int a, int b, ll c) {
        to[a].eb(b, c);
        to[b].eb(a, c);
    }

    /*
    function::ダイクストラ.特定の点からの距離.
    st::開始点.
    */
    vector<ll> dijkstra(int st) {
        vector<ll> dist(size, INF);
        vector<bool> vis(size);
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(0, st); dist[st] = 0;
        while (q.size()) {
            ll v, d; tie(d, v) = q.top(); q.pop();
            if (vis[v]) continue;
            vis[v] = true;
            for (auto p: to[v]) {
                ll nv, cost; tie(nv, cost) = p;
                if (vis[nv] || dist[nv] <= dist[v] + cost) continue;
                dist[nv] = dist[v] + cost;
                q.emplace(dist[nv], nv);
            }
        }
        return dist;
    }
};

int main() {
    //入力.
    int N, M; cin >> N >> M;

    //グラフ構築.
    graph g(N);
    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        g.merge(a, b, c);
    }

    //二点間をダイクストラで求める.
    vector<ll> d1 = g.dijkstra(0), d2 = g.dijkstra(N - 1);

    //頂点k経由の距離を求める.
    for (int k = 0; k < N; ++k) {
        ll d = d1[k] + d2[k];
        cout << d << endl;
    }
    return 0;
}