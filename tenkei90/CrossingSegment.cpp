#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main() {
    //入力.
    int N, M; cin >> N >> M;
    vector<int> L(M), R(M);
    for (int i = 0; i < M; ++i) {
        cin >> L[i] >> R[i]; --L[i]; --R[i];
    }

    /*
    //部分点1::全探索.
    int ans = 0;
    for (int i = 0; i < M - 1; ++i) {
        for (int j = i + 1; j < M; ++j) {
            //端点以外で交錯しているか.
            if (L[i] >= R[j] || L[j] >= R[i]) continue;
            int dl = L[j] - L[i], dr = R[j] - R[i];
            if (dl * dr > 0) ++ans;
        }
    }
    */
    
    //部分点2::Lを昇順にして,今見ているLより大きいLの中に存在するRを探索する.
    vector<P> senbun(M);
    for (int i = 0; i < M; ++i) senbun[i] = {L[i], R[i]};
    sort(senbun.begin(), senbun.end());

    //満点::BITで一気に計算.
    fenwick_tree<ll> fen(N + 1);
    for (int i = 0; i < M; ++i) {
        fen.add(senbun[i].se, 1);

        //Lが大きすぎて線分が交わらない場合の除外.
        fen.add(senbun[i].fi + 1, -1);
    }
    ll ans = 0, it = 0;
    for (int i = 0; i < M - 1; ++i) {
        //L[i]とL方向が一致する線分を消去.
        while (it < M && senbun[it].fi == senbun[i].fi) {
            fen.add(senbun[it].se, -1);
            fen.add(senbun[it].fi + 1, 1);
            ++it;
        }
        ans += fen.sum(senbun[i].se + 1, N);
    }

    //出力.
    cout << ans << endl;
    return 0;
}