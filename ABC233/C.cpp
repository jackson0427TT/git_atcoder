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
    ll N, X; cin >> N >> X;
    vector<vector<ll>> a(N);
    for (int i = 0; i < N; ++i) {
        int l; cin >> l;
        for (int j = 0; j < l; ++j) {
            ll x; cin >> x;
            a[i].eb(x);
        }
    }

    //積の更新.(情報保持用,更新用のmapを持つ.)
    map<ll, ll> cnt, nex;
    //初期化.
    cnt[1] = 1;
    for (int i = 0; i < N; ++i) {
        //更新開始.X以下のみ更新で枝刈り.
        nex.clear();
        for (int j = 0; j < (int)a[i].size(); ++j) {
            for (auto mp: cnt) {
                //オーバーフロー防止.
                if (a[i][j] > X / mp.fi) continue;
                nex[mp.fi * a[i][j]] += mp.se;
            }
        }
        cnt = nex;
    }

    //出力.
    cout << cnt[X] << endl;
    return 0;
}