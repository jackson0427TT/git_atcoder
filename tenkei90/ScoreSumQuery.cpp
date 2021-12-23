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

    //累積的に期末試験点数を積み重ねる.
    vector<vector<int>> S(N + 1, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        int c, p; cin >> c >> p; --c;

        //学籍番号i番の点数を加算.    
        S[i + 1][c] = S[i][c] + p;

        //i番でないクラスの点数を更新.
        c = (c + 1) % 2;
        S[i + 1][c] = S[i][c];
    }

    //クエリ処理.
    int Q; cin >> Q;
    while (Q--) {
        int l, r; cin >> l >> r; --l;
        int s1 = S[r][0] - S[l][0], s2 = S[r][1] - S[l][1];
        cout << s1 << " " << s2 << endl;
    }

    return 0;
}