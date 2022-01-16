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
    string s; cin >> s;

    //桁の総和を取る.
    int sum = 0;
    for (char c: s) sum += c - '0';

    //値を出して出力.
    int ans = sum * 111;
    cout << ans << endl;
    return 0;
}