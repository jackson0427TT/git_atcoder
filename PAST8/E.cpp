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
    int N, K; cin >> N >> K;
    vector<ll> c(N), p(N);
    for (ll& x: c) cin >> x;
    for (ll& x: p) cin >> x;

    //cをキーにして各色で最安値なTシャツをまとめる.
    unordered_map<ll, ll> p_min;
    for (int i = 0; i < N; ++i) {
        if (!p_min[c[i]]) p_min[c[i]] = p[i]; //p[i]>0よりempty代わりに使用.
        else p_min[c[i]] = min(p_min[c[i]], p[i]);
    }

    //配列に価格をまとめる.
    vector<ll> price;
    for (auto mp: p_min) price.eb(mp.se);

    //K種類ない場合の例外処理.
    if ((int)price.size() < K) {
        cout << -1 << endl;
        return 0;
    }

    //ソートして下からK個購入した結果を出力.
    sort(price.begin(), price.end());
    ll ans = 0;
    for (int i = 0; i < K; ++i) ans += price[i];
    cout << ans << endl;
    return 0;
}