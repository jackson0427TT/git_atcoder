#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

map<pair<ll, int>, ll> memo;

/*
function...A[it]を基準単位としてbase進数で表現した数と見なす.シフトしながら0になるよう処理.
X: A[it]の含まれる個数, it: Aにおけるイテレータ, A: 配列.
*/
ll f(ll X, int it, const vector<ll>& A) {
    //最大ケース.
    if (it == A.size() - 1) {
        return X;
    }

    //メモ化再起.
    if (memo.count({X, it})) return memo[{X, it}];

    ll base = A[it + 1] / A[it], rest = X % base;
    ll ret = min(f(X / base, it + 1, A) + rest, f((X + base - 1LL) / base, it + 1, A) + (base - rest));
    //メモ部.
    memo[{X, it}] = ret;
    return ret;
}

int main() {
    //入力.
    ll N, X; cin >> N >> X;
    vector<ll> A(N);
    for (ll& x: A) cin >> x;

    /*
    処理の全体像を考察.
    X % A[i + 1]をA[i]で処理 → X / A[i + 1] →...
    同様の処理を繰り返すので,関数で再帰的処理.
    */
    ll ans = f(X, 0, A);

    cout << ans << endl;
    return 0;
}