#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using T = tuple<ll, ll, ll>;

/*
function::x以下の等差数列要素のcounting.
Order::1
t::数列の要素, x::基準.
*/
ll count(T t, ll x) {
    ll a, b, c; tie(a, b, c) = t;
    ll a_max = (b <= x ? (x - b) / c + 1LL: 0LL);
    return min(a, a_max);
}

/*
function::二分探索の実行.
Order::NlogN
l, r::探索区間, A::等差数列の配列.
*/
ll BinarySearch(ll l, ll r, ll& K, const vector<T>& A) {
    while (r - l > 1LL) {
        ll m = (l + r) / 2LL, tot = 0;
        for (auto t: A) {
            tot += count(t, m);
        }
        if (tot >= K) r = m;
        else l = m;
    }
    return r;
} 

int main() {
    //入力.
    int N; cin >> N;
    ll K; cin >> K;

    vector<T> array(N);
    for (int i = 0; i < N; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        array[i] = {a, b, c};
    }

    //二分探索.
    ll ans = BinarySearch(0, 1e18, K, array);

    //出力.
    cout << ans << endl;
    return 0;
}