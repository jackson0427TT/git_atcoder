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
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    /*
    swapできないので,順列のパターンとして昇順,降順の並びしかできない.
    パターンごとに分けて処理.
    */
    int ans;
    if (p[0] + 1 == p[1] || (p[0] == n && p[1] == 1)) {
        if (p[0] == 1) ans = 0;
        else ans = min(n - p[0] + 1, p[0] + 1);
    }
    else {
        if (p[0] == n) ans = 1;
        else ans = min(p[0] + 1, n - p[0] + 1);
    }

    //出力.
    cout << ans << endl;
    return 0;
}