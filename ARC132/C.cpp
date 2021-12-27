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
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    //free[i]::順列におけるi+1の位置が自由か固定か.
    vector<bool> free(n, true);
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) free[a[i] - 1] = false;
    }

    /*
    今見ている位置±dの範囲の状態を持ちながらdp.
    m::状態数の上限.
    */
    int m = (1 << (2 * d + 1));
    vector<ll> dp(m), nex(m);

    //初期化.中心位置をit=-1に置いている.
    int st = 0;
    for (int i = 0; i < d; ++i) {
        st <<= 1;
        if (free[i]) ++st;
    }
    dp[st] = 1;

    /*
    更新.今見ている位置に対してずらすイメージで更新する.
    mask::上位桁を外す.
    */
    int mask = (1 << (2 * d + 1)) - 1;
    for (int i = 0; i < n; ++i) {
        nex.assign(m, 0);
        for (int b = 0; b < m; ++b) {
            //更新前の状態bからcにずらすように更新.
            int c = ((b << 1) & mask);
            if (i + d < n && free[i + d]) ++c;

            //今見ている中心iが固定か自由かで処理を変える.
            if (a[i] == -1) {

                //位置が固定されていない要素を当てはめる.
                for (int j = 0; j < 2 * d + 1; ++j) {
                    if (i + d - j < 0 || i + d - j > n - 1) continue;
                    if (c & (1 << j)) nex[c - (1 << j)] = (nex[c - (1 << j)] + dp[b]) % mod;
                }
            }
            else {
                nex[c] = (nex[c] + dp[b]) % mod;
            }
        }
        dp = nex;
    }

    //出力.
    cout << dp[0] << endl;
    return 0;
}