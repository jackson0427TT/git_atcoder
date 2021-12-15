#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

bool op(bool a, bool b) {return a | b;}
bool e() {return false;}
bool mapping(bool f, bool x) {return f ^ x;}
bool composition(bool f, bool g) {return f ^ g;}
bool id() {return false;}

int main() {
    //入力.
    int N, Q; cin >> N >> Q;

    //遅延セグ木の構築.
    lazy_segtree<bool, op, e, bool, mapping, composition, id> seg(2 * N + 1);

    //クエリ処理.
    while (Q--) {
        int t, k; cin >> t >> k;
        if (t == 1) cout << (seg.get(k) ? 2 * N + 1 - k: k) << endl;
        else seg.apply(N - k + 1, N + k + 1, true);
    }
    return 0;
}