#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

/*
function::dfsでの通過頂点を帰りがけ順に処理.
閉路が存在するのでbool配列で履歴を管理.
*/
void dfs1(int v, vector<bool>& vis, vector<int>& arr, vector<vector<int>>& G) {
    vis[v] = true;
    for (int nv :G[v]) {
        if (vis[nv]) continue;
        dfs1(nv, vis, arr, G);
    }
    arr.eb(v);
}

/*
function::dfsで辿った頂点数のカウント.
SCCでは逆行グラフを用いる.
*/
ll dfs2(int v, vector<bool>& vis, vector<vector<int>>& B) {
    vis[v] = true;
    ll cnt = 1;
    for (int nv: B[v]) {
        if (vis[nv]) continue;
        cnt += dfs2(nv, vis, B);
    }
    return cnt;
}

int main() {
    //入力.
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N), B(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        G[a].eb(b);
        B[b].eb(a);
    }

    //帰りがけ順に記録.
    vector<int> arr;
    vector<bool> vis(N);
    for (int i = 0; i < N; ++i) {
        if (vis[i]) continue;
        dfs1(i, vis, arr, G);
    }

    //番号の大きいものから逆行グラフで処理.
    vis.assign(N, false);
    ll ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (vis[arr[i]]) continue;
        ll cnt = dfs2(arr[i], vis, B);
        ans += cnt * (cnt - 1) / 2;
    }

    //出力.
    cout << ans << endl;
    return 0;
}