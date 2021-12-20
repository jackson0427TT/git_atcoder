#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main() {
    //入力.
    int H, W; cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) cin >> grid[i];

    //今まで通過したマス数を記録するdp.(初期化)
    vector<vector<int>> dp(H, vector<int>(W));
    dp[0][0] = 1;
    //配るdpで更新.
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            //配り元が0だったら無視.((0, 0)から辿ってこれてない)
            if (!dp[i][j]) continue;
            
            if (i < H - 1 && grid[i + 1][j] != '#') {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
            }
            if (j < W - 1 && grid[i][j + 1] != '#') {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1);
            }
        }
    }

    //最大値を求める.
    int ans = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }

    //出力.
    cout << ans << endl;
    return 0;
}