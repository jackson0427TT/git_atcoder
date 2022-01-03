#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;

int main() {
    //入力.
    ld T, L, X, Y; cin >> T >> L >> X >> Y;
    int Q; cin >> Q;

    //観覧車上の位置から俯角を計算.
    auto calc = [&](ld y, ld z) {
        ld xy = sqrt(X * X + (Y - y) * (Y - y));
        return atan2(z, xy) * 180.0 / M_PI;
    };

    //クエリ処理.
    while (Q--) {
        int e; cin >> e;
        ld t = e % (int)T;
        ld y = -L / 2 * sin(t / T * 2 * M_PI), z = L / 2 * (1 - cos(t / T * 2 * M_PI));

        //精度に注意しつつ出力.
        cout << fixed << setprecision(15) << calc(y, z) << endl;
    }
    return 0;
}