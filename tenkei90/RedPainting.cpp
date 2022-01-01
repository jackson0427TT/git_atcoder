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
    int H, W, Q; cin >> H >> W >> Q;

    //unionfind木でマス同士の接続を管理.
    dsu d(H * W);
    vector<bool> red(H * W);

    //クエリ処理.
    const vector<int> dr = {1, 0, -1, 0}, dc = {0, 1, 0, -1};
    while (Q--) {
        int t; cin >> t;

        //赤マス追加処理.
        if (t == 1) {
            int r, c; cin >> r >> c; --r; --c;
            int p = W * r + c;

            //隣接する赤マス同士を接続.
            red[p] = true;
            for (int dir = 0; dir < 4; ++dir) {
                int nr = r + dr[dir], nc = c + dc[dir];
                //座標変換前にテーブル内外の判定をする!
                if (nr < 0 || nr > H - 1 || nc < 0 || nc > W - 1) continue;
                int np = W * nr + nc;
                if (red[np]) d.merge(p, np);
            }
        }

        //接続判定.
        if (t == 2) {
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; --r1; --c1; --r2; --c2;
            int p1 = W * r1 + c1, p2 = W * r2 + c2;
            //赤マスかつ接続されているか.
            if (red[p1] && d.same(p1, p2)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}