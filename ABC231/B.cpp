#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N; cin >> N; //N: 票数.
    
    map<string, int> cnt; //cnt: keyに候補者名,valueに得票数.
    for (int i = 0; i < N; ++i) {
        string name; cin >> name;
        ++cnt[name]; //票を数える.
    }

    //各候補の得票数から最大のものを探す.
    int c_max = 0;
    string ans;
    for (auto mp: cnt) {
        if (c_max < mp.se) {
            c_max = mp.se;
            ans = mp.fi;
        }
    }

    cout << ans << endl; //出力.
    return 0;
}