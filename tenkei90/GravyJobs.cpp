#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using T = tuple<ll, ll, ll>;

int main() {
    //入力.
    int N; cin >> N;
    vector<T> Task(N);
    for (int i = 0; i < N; ++i) {
        ll d, c, s; cin >> d >> c >> s;
        Task[i] = {d, c, s};
    }

    //タスクを締め切りの長い順に並べ替える.
    sort(Task.rbegin(), Task.rend());

    //dp[i]::i日目の終わりから始めた場合の最大報酬.
    int M = get<0>(Task[0]);
    vector<ll> dp(M + 1);
    //タスクの締め切り基準で考えると,タスク開始時の最大報酬が分かる.
    for (int i = 0; i < N; ++i) {
        ll d, c, s; tie(d, c, s) = Task[i];
        for (int j = c; j <= d; ++j) {
            dp[j - c] = max(dp[j - c], dp[j] + s);
        }
    }

    //出力.
    ll ans = 0;
    for (int i = 0; i <= M; ++i) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}