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
    int N; cin >> N;

    //欠番による修正.
    if (N >= 42) ++N;

    //構築.
    string num = to_string(N);
    while (num.size() < 3) {
        num = '0' + num;
    }

    //出力.
    cout << "AGC" << num << endl;
    return 0;
}