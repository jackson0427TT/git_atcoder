#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    double D; cin >> D; //double型として入力.

    double ans = D / 100; //ans: 型推論を利用して計算.

    cout << fixed << setprecision(15) << ans << endl; //精度に注意して出力.

    return 0;
}