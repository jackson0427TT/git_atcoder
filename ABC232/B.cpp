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
    string s, t; cin >> s >> t;

    //s→tに必要な変換値Kをit=0に対して求めておく.
    int dif = t[0] - s[0];
    if (dif < 0) dif += 26;

    //各イテレータに対してK=difで一致するかを確認.
    for (int i = 0; i < (int)s.size(); ++i) {
        int val = t[i] - s[i];
        if (val < 0) val += 26;

        //操作によってs=tにできないなら強制終了.
        if (dif != val) {
            cout << "No" << endl;
            return 0;
        }
    }

    //問題がなかった場合Yesを出力.
    cout << "Yes" << endl;
    return 0;
}