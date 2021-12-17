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
    vector<int> A(N);
    for (int& x: A) cin >> x;

    //二分探索前の処置.
    sort(A.begin(), A.end());

    //生徒ごとにクエリ処理.
    int Q; cin >> Q;
    while (Q--) {
        int b; cin >> b;
        auto it = lower_bound(A.begin(), A.end(), b) - A.begin();
        int ans = abs(A[it] - b);
        if (it != 0) ans = min(ans, abs(b - A[it - 1]));
        cout << ans << endl;
    }
    return 0;
}