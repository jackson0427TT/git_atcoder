#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> B(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> B[i][j];
    }

    //列方向に正しいかの確認。
    for (int i = 0; i < M - 1; ++i) {
        if (B[0][i] + 1 != B[0][i + 1] || B[0][i] % 7 == 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    //行方向に正しいかの確認。
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < M; ++j) {
            if (B[i][j] + 7 != B[i + 1][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}