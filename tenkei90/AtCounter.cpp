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
    int N; string S; cin >> N >> S;

    //初期状態の設定.dp[i][j]::S[i - 1]文字目まででat[j - 1]まで並べている状況.
    const string at = "atcoder";
    vector<vector<ll>> dp(N + 1, vector<ll>(8));
    dp[0][0] = 1;

    //dp処理.
    for (int i = 0; i < N; ++i) {
        char c = S[i];
        for (int j = 0; j < 8; ++j) {
            if (j && at[j - 1] == c) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1]) % mod;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
        }
    }

    //出力.
    cout << dp[N][7] << endl;
    return 0;
}