#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    //入力.
    int N, M; cin >> N >> M;

    //初期状態の作成.
    vector<int> cnt(N); //cnt[i]: iの隣にいる人数.
    dsu d(N); //d: uf木.閉路検出用.

    //条件に合わせて処理.横一列にできないなら強制終了.
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        ++cnt[a];
        ++cnt[b];
        if (cnt[a] > 2 || cnt[b] > 2 || d.same(a, b)) {
            cout << "No" << endl;
            return 0;
        }
        d.merge(a, b);
    }

    //条件を全て処理出来たらok.
    cout << "Yes" << endl;
    return 0;
}