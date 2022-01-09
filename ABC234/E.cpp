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
    ll X; cin >> X;

    //一桁の場合のみ例外処理.
    if (X < 10) {
        cout << X << endl;
        return 0;
    }

    //全探索.(len::数字列の長さ,sta::開始位置,dif::等差の差分)
    set<ll> st;
    for (int len = 1; len <= 18; ++len) {
        for (int sta = 1; sta <= 9; ++sta) {
            for (int dif = -9; dif <= 8; ++dif) {
                ll x = sta;
                for (int i = 1; i < len; ++i) {
                    ll nex = x % 10 + dif;
                    if (nex < 0 || nex > 9) break;
                    x = x * 10 + nex;
                    if (i == len - 1) st.insert(x);
                }
            }
        }
    }

    //二分探索.
    auto ptr = st.lower_bound(X);

    //出力.
    cout << *ptr << endl;
    return 0;
}