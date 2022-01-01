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
    vector<ll> A(N), B(N);
    for (ll& x: A) cin >> x;
    for (ll& x: B) cin >> x;

    //生徒,学校双方をソート.
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    //前方から貪欲にマッチング.
    ll ans = 0;
    for (int i = 0; i < N; ++i) ans += abs(A[i] - B[i]);

    //出力.
    cout << ans << endl;
    return 0;
}