#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> topological_sort (const vector<vector<int>> &to, const vector<vector<int>> &from) {
    int N = to.size();
    vector<int> vin(N);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < N; ++i) {
        if(from[i].empty())q.push(i);
        vin[i] = from[i].size();
    }

    vector<int> ret;
    while (q.size()) {
        int v = q.top(); q.pop();
        ret.emplace_back(v);
        for (int nv: to[v]) {
            --vin[nv];
            if (!vin[nv]) q.push(nv);
        }
    }

    return ret;
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N), B(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        G[a].emplace_back(b);
        B[b].emplace_back(a);
    }

    vector<int> ans = topological_sort(G, B);

    if (ans.size() == N) {
        for (int x: ans) cout << x + 1 << " ";
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
}