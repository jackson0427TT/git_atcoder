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
    ll K; cin >> K;

    //下桁から二進数表記(1の代わりに2)に並べる.でかすぎるのでstring処理.
    string ans;
    while (K) {
        ans += '0' + (K & 1LL ? 2: 0);
        K >>= 1;
    }
    reverse(ans.begin(), ans.end());

    //出力.
    cout << ans << endl;
    return 0;
}