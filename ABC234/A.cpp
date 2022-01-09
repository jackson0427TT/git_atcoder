#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
//問題の指示通りの関数.
int f(int x) {return x * x + 2 * x + 3;}

int main() {
    //入力.
    int t; cin >> t;

    //出力.
    int ans = f(f(f(t) + t) + f(f(t)));
    cout << ans << endl;
    return 0;
}