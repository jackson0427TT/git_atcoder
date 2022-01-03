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
    ll A, B, C; cin >> A >> B >> C;

    //最大公約数の立方体キューブを作ればよい.
    ll g = __gcd(A, __gcd(B, C)), ans = (A + B + C) / g - 3;

    //出力.
    cout << ans << endl;
    return 0;
}