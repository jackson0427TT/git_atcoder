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
    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    //行,列ごとの総和.
    vector<int> Sh(H), Sw(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            Sh[i] += A[i][j];
            Sw[j] += A[i][j];
        }
    }

    //出力.
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int tot = Sh[i] + Sw[j] - A[i][j];
            cout << tot << " ";
        }
        cout << endl;
    }
    return 0;
}