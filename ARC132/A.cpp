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
    int N; cin >> N;
    vector<int> R(N), C(N);
    for (int i = 0; i < N; ++i) cin >> R[i];
    for (int i = 0; i < N; ++i) cin >> C[i];

    /*
    クエリ処理.
    R[r]+C[c]>=N+1でないと黒マスではない.
    */
    int Q; cin >> Q;
    while (Q--) {
        int r, c; cin >> r >> c; --r; --c;
        if (R[r] + C[c] >= N + 1) cout << '#';
        else cout << '.';
    }
    cout << endl;
    return 0;
}