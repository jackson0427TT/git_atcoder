#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
const ll INF = 8e18;

int main() {
    //入力.
    ll N, X, Y; cin >> N >> X >> Y;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    //初期化.dp[i][j]::A[i - 1]まで更新位置を決定していて,状態jにおけるコストの最小値.
    vector<vector<ll>> dp(N + 1, vector<ll>(1 << N, INF));
    dp[0][0] = 0;

    /*
    A[i]を指定位置に追加する方針で更新.
    cnt::A[i]とB[j]を対応させた場合の追加転倒数.
    cost::A[i]とB[j]を対応させた場合の追加コスト.
    */
    for (int i = 0; i < N; ++i) {
        for (int b = 0; b < (1 << N); ++b) {
            if (dp[i][b] == INF) continue;
            int cnt = __builtin_popcount(b);
            for (int j = 0; j < N; ++j) {
                if (b & (1 << j)) {
                    --cnt;
                    continue;
                }
                ll cost = X * abs(A[i] - B[j]) + Y * cnt;
                dp[i + 1][b + (1 << j)] = min(dp[i + 1][b + (1 << j)], dp[i][b] + cost);
            }
        }
    }

    //出力.
    cout << dp[N][(1 << N) - 1] << endl;
    return 0;
}