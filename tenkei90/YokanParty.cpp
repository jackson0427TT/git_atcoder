#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

//function::yokanを切り分けられる個数を返す.
ll cut_yokan(const ll m, const vector<ll>& A) {
    ll ret = 0, now = 0;
    for (ll x: A) {
        if (x - now >= m) {
            now = x;
            ++ret;
        }
    }
    return ret;
}

/*
function::二分探索で最大スコアを探る.
Order::NlogN
l, r::探索範囲, K::切り分け個数, A::配列
*/
ll BinarySearch(ll l, ll r, const ll& K, const vector<ll>& A) {
    while (r - l > 1) {
        ll m = (l + r) / 2LL;
        //m以上の長さで切り分けられる個数.
        ll cnt = cut_yokan(m, A);
        if (cnt >= K) l = m;
        else r = m;
    }
    return l;
}

int main() {
    //入力.
    ll N, L, K; cin >> N >> L >> K; ++K;
    vector<ll> A(N);
    for (ll& x: A) cin >> x;
    A.eb(L);

    //二分探索.
    ll ans = BinarySearch(1, (ll)1e9 + 1LL, K, A);

    //出力.
    cout << ans << endl;
    return 0;
}