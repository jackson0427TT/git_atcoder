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
    int X, Y; cin >> X >> Y;

    //切り上げ計算.
    int ans = (max(0, Y - X) + 9) / 10;

    //出力.
    cout << ans << endl;
    return 0;
}