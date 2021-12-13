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
    int N, X; cin >> N >> X;
    vector<int> A(N);
    for (int& x: A) cin >> x;

    //Xをカウント処理.
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == X) ++ans;
    }

    //出力.
    cout << ans << endl;
    return 0;
}