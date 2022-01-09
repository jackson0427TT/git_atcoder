#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
const ll mod = 998244353;
vector<ll> fact, fact_inv, inv;

void init_nCk(int size) {
    fact.resize(size + 5);
    fact_inv.resize(size + 5);
    inv.resize(size + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i <= size; i++){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

int main() {
    //入力.
    string S; cin >> S;
    int n = S.size();

    //文字種別にカウント.
    vector<ll> cnt(26);
    for (char c: S) ++cnt[c - 'a'];

    //nCkの準備.
    init_nCk(n);
    auto combination = [&](int n, int r) {
        return fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod;
    };

    /*
    丁寧に挿入DP.
    dp[i][j]::i種類目の文字を入れて長さがjとなる文字列.(N^2が可能なのでこれで問題ない.)
    */
    vector<vector<ll>> dp(27, vector<ll>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i < 26; ++i) {
        //j::元々の長さ, k::新たに加える長さ.
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; (j + k <= n && k <= cnt[i]); ++k) {
                dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * combination(j + k, j) % mod) % mod;
            }
        }
    }

    //空文字列以外の全てを回収.
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + dp[26][i]) % mod;
    cout << ans << endl;
    return 0;
}