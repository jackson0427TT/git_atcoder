#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    //入力.
    ll N, D; cin >> N >> D;
    vector<ll> L(N), R(N);
    for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];

    //全ての壁をpriority_queueに格納.貪欲クエリとみると配列よりもキューの方がイメージとして適切.
    priority_queue<P, vector<P>, greater<P>> q;
    for (int i = 0; i < N; ++i) {
        q.emplace(R[i], L[i]);
    }

    //貪欲処理.必要なパラメータを用意.
    ll ans = 0, broken = 0;
    while (q.size()) {
        ll l, r; tie(r, l) = q.top(); q.pop();
        //高橋君が破壊した範囲と被らない場合は処理.
        if (l > broken) {
            ++ans;
            broken = r + D - 1LL;
        }
    }

    //出力.
    cout << ans << endl;
    return 0;
}