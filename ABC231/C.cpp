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
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (int& x: A) cin >> x;

    //ソートしておく.
    sort(A.begin(), A.end());

    //クエリ処理.
    while (Q--) {
        int x; cin >> x;
        auto it = lower_bound(A.begin(), A.end(), x) - A.begin();
        int ans = N - it;
        cout << ans << endl;
    }
    return 0;
}