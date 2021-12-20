#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
const ll mod = 998244353;

int main() {
    //入力.
    ll H, W, K; cin >> H >> W >> K;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    //dp[i][j][k]::i回の移動が済んでおり,j::x2であるか,k::y2であるかのbool的位置情報.
    vector<vector<vector<ll>>> dp(K + 1, vector<vector<ll>>(2, vector<ll>(2)));
    
    //初期化.
    if (x1 == x2) {
        if (y1 == y2) dp[0][1][1] = 1;
        else dp[0][1][0] = 1;
    }
    else {
        if (y1 == y2) dp[0][0][1] = 1;
        else dp[0][0][0] = 1;
    }

    //一回ずつ丁寧に移動させる.
    for (int i = 0; i < K; ++i) {
        dp[i + 1][0][0] = ((dp[i][0][0] * (H + W - 4) % mod + dp[i][1][0] * (H - 1) % mod) % mod + dp[i][0][1] * (W - 1) % mod) % mod;
        dp[i + 1][1][0] = ((dp[i][0][0] + dp[i][1][0] * (W - 2) % mod) % mod + dp[i][1][1] * (W - 1) % mod) % mod;
        dp[i + 1][0][1] = ((dp[i][0][0] + dp[i][0][1] * (H - 2) % mod) % mod + dp[i][1][1] * (H - 1) % mod) % mod;
        dp[i + 1][1][1] = (dp[i][1][0] + dp[i][0][1]) % mod;
    }

    //出力.
    cout << dp[K][1][1] << endl;
    return 0;
}