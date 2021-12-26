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
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    for (ll& x: A) cin >> x;

    //累積和を取る.
    vector<ll> S(N + 1);
    for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];

    //後方の累積和のカウント.
    map<ll, ll> cnt;
    for (int i = 1; i < N + 1; ++i) ++cnt[S[i]];

    //下方から総和Kとなる値を詰める.
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        //x::l=iの際に解となる値.
        ll x = S[i] + K;
        ans += cnt[x];

        //更新処理.
        --cnt[S[i + 1]];
    }

    //出力.
    cout << ans << endl;
    return 0;
}