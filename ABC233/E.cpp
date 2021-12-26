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
    string X; cin >> X;

    //全桁の総和を出す.
    ll sum = 0;
    for (char& c: X) {
        sum += (ll)(c - '0');
    }

    /*
    下桁から更新.
    rest::繰り上げ保持.
    */
    string ans;
    ll rest = sum;
    for (int i = (int)X.size() - 1; i >= 0; --i) {
        //今見ている桁の更新.
        char x = (ll)(rest % 10LL) + '0';
        ans += x;

        //繰り上げ部の更新.
        rest /= 10LL;
        sum -= (ll)(X[i] - '0');
        rest += sum;
    }

    //残った繰り上げの処理&解の成形.
    reverse(ans.begin(), ans.end());
    if (rest) ans = to_string(rest) + ans;

    //出力.
    cout << ans << endl;
    return 0;
}