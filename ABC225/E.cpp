#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using P = pair<ld, ld>;

int main() {
    int N; cin >> N;
    vector<P> pos(N);
    for (int i = 0; i < N; ++i) {
        ll x, y; cin >> x >> y;
        pos[i] = {x, y};
    }

    vector<P> r(N);
    for (int i = 0; i < N; ++i) {
        ld x, y; tie(x, y) = pos[i];
        ld t1 = (y - 1.0) / x, t2 = (x == 1.0 ? 1e9 + 100.0: y / (x - 1.0));
        r[i] = {t2, t1};
    }

    sort(r.begin(), r.end());

    int ans = 0;
    ld now = 0;
    for (int i = 0; i < N; ++i) {
        ld t2, t1; tie(t2, t1) = r[i];
        if (t1 - now < 0.0) continue;
        ++ans;
        now = t2;
    }

    cout << ans << endl;
    return 0;
}