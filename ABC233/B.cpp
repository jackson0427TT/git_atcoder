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
    int L, R; cin >> L >> R; --L;
    string S; cin >> S;

    //反転部分の保持.
    string T = S.substr(L, R - L);
    reverse(T.begin(), T.end());

    //構築,出力.
    string ans = S.substr(0, L) + T + S.substr(R);
    cout << ans << endl;
    return 0;
}