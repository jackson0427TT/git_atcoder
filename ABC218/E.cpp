#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using tlll = tuple<ll, ll, ll>;

int main() {
    int N, M; cin >> N >> M;
    ll tot = 0;
    priority_queue<tlll, vector<tlll>, greater<tlll>> pq;
    for (int i = 0; i < M; ++i) {
        ll u, v, c; cin >> u >> v >> c; --u; --v;
        tot += c;
        pq.emplace(c, u, v);
    }

    dsu d(N);
    while (pq.size()) {
        int u, v; ll c; tie(c, u, v) = pq.top(); pq.pop();
        if (d.same(u, v) && c >= 0) continue;
        tot -= c;
        d.merge(u, v);
    }

    cout << tot << endl;
}