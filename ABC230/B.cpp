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
    string S; cin >> S;

    //Tの構築.
    string T, base = "oxx";
    for (int i = 0; i < 10; ++i) T += base;

    //baseの繰り返しより,位置調整しつつ判定.
    int S_size = S.size();
    for (int i = 0; i < 3; ++i) {
        string t = T.substr(i, S_size);
        if (S == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}