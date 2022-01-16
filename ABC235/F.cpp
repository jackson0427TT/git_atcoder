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
    string N; int M; cin >> N >> M;
    vector<int> C(M);
    for (int i = 0; i < M; ++i) cin >> C[i];
    int n = N.size();

    //桁dpの準備.総和,個数を別で保持することに注意.初期化も簡潔.
    vector<vector<ll>> dp(2, vector<ll>(1 << 10)), nex, cnt(2, vector<ll>(1 << 10)), nc;
    int st = N[0] - '0';
    for (int i = 1; i <= st; ++i) {
        if (i != st) {
            dp[0][1 << i] = i;
            cnt[0][1 << i] = 1;
        }
        else {
            dp[1][1 << i] = i;
            cnt[1][1 << i] = 1;
        }
    }

    /*
    桁dp.個数に応じて付加が変わることも忘れずに.
    ma::次に見る桁の値. j::更新前の状態. k::今の数字の下桁に付加する値.
    */
    for (int i = 1; i < n; ++i) {
        int ma = N[i] - '0';
        nex.assign(2, vector<ll>(1 << 10, 0));
        nc.assign(2, vector<ll>(1 << 10, 0));
        for (int j = 1; j < (1 << 10); ++j) {
            for (int k = 0; k < 10; ++k) {
                int ncon = j | (1 << k);
                if (dp[0][j]) {
                    nex[0][ncon] = (nex[0][ncon] + (dp[0][j] * 10 % mod + k * cnt[0][j] % mod) % mod) % mod;
                    nc[0][ncon] = (nc[0][ncon] + cnt[0][j]) % mod;
                }
                if (k < ma && dp[1][j]) {
                    nex[0][ncon] = (nex[0][ncon] + (dp[1][j] * 10 % mod + k * cnt[1][j] % mod) % mod) % mod;
                    nc[0][ncon] = (nc[0][ncon] + cnt[1][j]) % mod;
                }
                if (k == ma && dp[1][j]) {
                    nex[1][ncon] = (nex[1][ncon] + (dp[1][j] * 10 % mod + k * cnt[1][j] % mod) % mod) % mod;
                    nc[1][ncon] = (nc[1][ncon] + cnt[1][j]) % mod;
                }
            }
        }

        //新しく今見ている桁から始まる数列を追加.
        for (int k = 1; k < 10; ++k) {
            nex[0][1 << k] = (nex[0][1 << k] + k) % mod;
            nc[0][1 << k] = (nc[0][1 << k] + 1) % mod;
        }

        //更新.
        dp = nex; cnt = nc;
    }

    //Cに関しての条件を満たすものを選択.
    ll ans = 0;
    for (int b = 1; b < (1 << 10); ++b) {
        for (int i = 0; i < M; ++i) {
            if (!(b & (1 << C[i]))) break;
            if (i == M - 1) {
                ans = (ans + (dp[0][b] + dp[1][b])) % mod;
            }
        }
    }

    //出力.
    cout << ans << endl;
    return 0;
}