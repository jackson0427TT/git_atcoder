#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
vector<ll> fact, fact_inv, inv;

void init_nCk(int size) {
    fact.resize(size + 5);
    fact_inv.resize(size + 5);
    inv.resize(size + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i <= size; i++){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

int main() {
    //入力.
    int N; cin >> N;

    //nCrの計算の前準備.
    init_nCk(N);
    auto combination = [&](const int n, const int r) {
        return fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod;
    };

    /*
    クエリ(kのとき)を解く.
    ボールi個に対して別々に計算して解く.
    (i - 1) * (k - 1)::選択したボールの間にある空間の総和.
    */
    for (int k = 1; k <= N; ++k) {
        ll tot = 0;
        for (int i = 1; i + (i - 1) * (k - 1) <= N; ++i) {
            tot = (tot + combination(N - (k - 1) * (i - 1), i)) % mod;
        }
        cout << tot << endl;
    }
    return 0;
}