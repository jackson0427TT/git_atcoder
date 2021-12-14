#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

//グラフの構造体.
struct graph {
    int size;
    vector<vector<int>> to;

    graph(int N): size(N), to(vector<vector<int>>(N)) {}

    void merge(int a, int b) {
        to[a].eb(b);
        to[b].eb(a);
    }
    vector<int> bfs(int st) {
        vector<int> dist(size, -1);
        queue<int> q;
        dist[st] = 0;
        q.push(st);
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int nv: to[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
        return dist;
    }
};

int main() {
    //入力.
    int N; cin >> N;
    graph g(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        g.merge(a, b);
    }

    //木の直径を求める.
    vector<int> d = g.bfs(0);
    int st = 0, d_max = 0;
    for (int i = 0; i < N; ++i) {
        if (d_max < d[i]) {
            d_max = d[i];
            st = i;
        }
    }
    vector<int> dM = g.bfs(st);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, dM[i] + 1);
    }

    //出力.
    cout << ans << endl;
    return 0;
}