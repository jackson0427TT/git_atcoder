#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;

ld calc(ld x1, ld x2, ld y1, ld y2) {
    ld dx = x2 - x1, dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    //入力.
    int N; cin >> N;
    vector<ld> x(N), y(N);
    for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

    //全探索で距離計算.
    ld ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ld dist = calc(x[i], x[j], y[i], y[j]);
            ans = max(ans, dist);
        }
    }

    //出力.
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}