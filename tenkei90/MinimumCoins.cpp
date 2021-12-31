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
    ll N, A, B, C; cin >> N >> A >> B >> C;

    /*
    A,Bの枚数を全探索.
    forループ内...c_maxを超えないこと,丁度N円になることを前提に最小枚数を計算.
    */
    const int c_max = 9999;
    int ans = c_max;
    for (int i = 0; i <= c_max; ++i) {
        for (int j = 0; i + j <= c_max; ++j) {
            ll rest = N - A * i - B * j;
            if (rest % C || rest < 0 || C * (c_max - i - j) < rest) continue;
            ans = min((ll)ans, i + j + rest / C);
        }
    }

    //出力.
    cout << ans << endl;
    return 0;
}