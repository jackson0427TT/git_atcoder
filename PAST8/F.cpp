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
    int N; string S; cin >> N >> S;

    //0部で環状配列を生成し,Pを構築出来るようにする.
    vector<int> s0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') s0.eb(i + 1);
    }
    if (s0.size()) s0.eb(s0[0]); //if文::Sの要素が全て1出ないことの確認

    //0が一つのみの例外処理.
    if (s0.size() == 2) {
        cout << -1 << endl;
        return 0;
    }

    //1_indexedでPを構築.
    vector<int> P(N + 1);
    int j = 0;
    for (int i = 1; i <= N; ++i) {
        //s0の要素であれば一つ後のs0要素にずらす.
        if (s0.size() && s0[j] == i) {
            P[i] = s0[j + 1];
            ++j;
        }
        else {
            P[i] = i;
        }
    }

    //出力.
    for (int i = 1; i <= N; ++i) cout << P[i] << " ";
    cout << endl;
    return 0;
}