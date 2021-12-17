#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
const ll mod = 1000000007;

int main() {
    //入力.
    ll N, B, K; cin >> N >> B >> K;
    vector<int> c(K);
    for (int i = 0; i < K; ++i) cin >> c[i];

    //ダブリング用10累乗.
    vector<ll> x(61);
    x[0] = 10;
    for (int i = 0; i < 60; ++i) x[i + 1] = x[i] * x[i] % B;　//modでなくBでの剰余.

    //タブリングで2の指数乗長のパターンを導出.
    vector<vector<ll>> dp(61, vector<ll>(B));
    for (int i = 0; i < K; ++i) ++dp[0][c[i] % B];
    for (int b = 0; b < 60; ++b) {
        for (ll i = 0; i < B; ++i) {
            for (ll j = 0; j < B; ++j) {
                ll val = (i * x[b] % B + j) % B; //modとBの剰余を被らせるとバグるので注意.
                dp[b + 1][val] = (dp[b + 1][val] + dp[b][i] * dp[b][j] % mod) % mod;
            }
        }
    }

    //N=(2の指数乗の組み合わせ)であることを利用して解く.
    vector<ll> ans(B), nex;
    ans[0] = 1;
    for (int b = 0; b < 60; ++b) {
        if (N & (1LL << b)) {
            nex.assign(B, 0);
            for (ll i = 0; i < B; ++i) {
                for (ll j = 0; j < B; ++j) {
                    ll val = (i * x[b] % B + j) % B;
                    nex[val] = (nex[val] + ans[i] * dp[b][j] % mod) % mod;
                }
            }
            ans = nex;
        }
    }

    cout << ans[0] << endl;
    return 0;
}