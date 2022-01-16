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
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    //登れるところまで登る.
    int it = 0;
    while (it < N - 1 && H[it] < H[it + 1]) ++it;

    //出力.
    cout << H[it] << endl;
    return 0;
}