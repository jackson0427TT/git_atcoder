#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using T = tuple<ll, int, int, int>;

int main() {
    //入力.
    int N, M, Q; cin >> N >> M >> Q;

    /*
    辺,クエリを一気に読む.タプル内(重み,辺の端点2つ,辺の性質のフラグ.)
    優先度キュー::MSTの作成に必要.
    フラグに関して::解はクエリ順に出す必要があるので,そのイテレータを記録.元の辺は-1.
    */
    priority_queue<T, vector<T>, greater<T>> q;

    //元のグラフの辺を入力.
    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        q.emplace(c, a, b, -1);
    }

    //クエリの辺を入力.
    for (int i = 0; i < Q; ++i) {
        int u, v, w; cin >> u >> v >> w; --u; --v;
        q.emplace(w, u, v, i);
    }

    //最小全域木の製作.クエリ辺は利用しないことに注意.
    vector<bool> ans(Q);
    dsu d(N);
    while (q.size()) {
        int u, v, w, it; tie(w, u, v, it) = q.top(); q.pop();
        if (d.same(u, v)) continue;
        if (it != -1) ans[it] = true;
        else d.merge(u, v);
    }

    //出力.
    for (int i = 0; i < Q; ++i) {
        cout << (ans[i] ? "Yes": "No") << endl;
    }
    return 0;
}