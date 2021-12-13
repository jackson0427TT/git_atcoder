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
    int A, B, C, D; cin >> A >> B >> C >> D;

    //計算.
    int ans = min(A + B - C, D);

    //出力.
    cout << ans << endl;
    return 0;
}