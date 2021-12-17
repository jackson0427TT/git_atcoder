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
    int N, K; cin >> N >> K;
    string S; cin >> S;

    //各文字の経路表を製作.nex[i][j]::(char)('a' + i)の文字がj文字目以降に現れる最初の位置.
    vector<vector<int>> nex(26, vector<int>(N, N));
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (S[i] == (char)('a' + j)) nex[j][i] = i;
            else if (i < N - 1) nex[j][i] = nex[j][i + 1];
        }
    }

    //辞書順最小となるよう製作.
    string ans;
    int now = 0, len = 0;
    while (len < K) {
        int lim = N - (K - len);
        for (int i = 0; i < 26; ++i) {
            if (nex[i][now] <= lim) {
                ans += (char)('a' + i);
                now = nex[i][now] + 1;
                ++len;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}