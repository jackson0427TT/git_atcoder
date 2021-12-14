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
    ll N; cin >> N;

    //i=>√Nの範囲に対して,結果となる整数xの個数で計算.
    //i_min::上方から見ていって,まだ使われていない最大のi.
    ll ans = 0, i_min = N;
    for (ll x = 1; x * x <= N; ++x) {
        //[N/i]=xとなるiの個数.
        ll cnt = N / x - N / (x + 1LL);
        i_min = min(i_min, N / (x + 1LL));
        ans += x * cnt;
    }

    //i<√Nの範囲に対して,個別に計算.
    for (ll i = 1; i <= i_min; ++i) {
        ans += N / i;
    }

    //出力.
    cout << ans << endl;
    return 0;
}