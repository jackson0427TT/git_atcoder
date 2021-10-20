#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int bfs(int ng, vector<vector<int>>& G, vector<vector<int>>& Edge) {
    int N = G.size();
    vector<int> dist(N, -1);
    queue<int> q;
    dist[0] = 0; q.push(0);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (int nv: G[v]) {
            if (Edge[v][nv] == ng || dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    return dist[N - 1];
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> Edge(N, vector<int>(N)), G(N);
    for (int i = 0; i < M; ++i) {
        int from, to; cin >> from >> to; --from; --to;
        Edge[from][to] = i;
        G[from].emplace_back(to);
    }

    vector<int> dist(N, -1), par(N, -1);
    queue<int> q;
    dist[0] = 0; q.push(0);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (int nv: G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            par[nv] = v;
            q.push(nv);
        }
    }

    int d_min = dist[N - 1], now = N - 1;
    vector<int> used;
    while (true) {
        int bv = par[now];
        if (bv == -1) break;
        used.emplace_back(Edge[bv][now]);
        now = bv;
    }
    sort(used.begin(), used.end());

    int it = 0;
    vector<int> ans(M);
    for (int i = 0; i < M; ++i) {
        if (it < used.size() && i == used[it]) {
            ans[i] = bfs(i, G, Edge);
            ++it;
        }
        else ans[i] = d_min;
    }

    for(int x: ans)cout << x << endl;
}