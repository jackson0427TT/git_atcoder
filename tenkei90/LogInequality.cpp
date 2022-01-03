#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

ll my_pow(ll x, ll a) {
    ll ret = 1;
    while (a) {
        ret *= x;
        --a;
    }
    return ret;
}

int main() {
    //入力.
    ll a, b, c; cin >> a >> b >> c;

    //13^17が64byteに収まると信じて処理.
    ll x = my_pow(c, b);
    cout << (a < x ? "Yes": "No") << endl;
    return 0;
}