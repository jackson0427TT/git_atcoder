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
    int H, W; cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) cin >> grid[i];

    //BFSで終了.
    const vector<int> dx = {1, 0}, dy = {0, 1};
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<P> q;

    //初期条件.
    dist[0][0] = 0;
    q.emplace(0, 0);
    while (q.size()) {
        //探索するgrid上の位置を取り出す.
        int h, w; tie(h, w) = q.front(); q.pop();
        for (int dir = 0; dir < 2; ++dir) {
            int nh = h + dx[dir], nw = w + dy[dir];

            //場外,探索済み,壁マスの場合を無視.
            if (nh > H - 1 || nw > W - 1) continue;
            if (dist[nh][nw] != -1 || grid[nh][nw] == '#') continue;

            //更新.
            dist[nh][nw] = dist[h][w] + 1;
            q.emplace(nh, nw);
        }
    }

    int d_max = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            d_max = max(d_max, dist[i][j]);
        }
    }

    int ans = d_max + 1;
    cout << ans << endl;
    return 0;
}