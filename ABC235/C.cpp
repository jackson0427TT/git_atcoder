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
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    //値をキーとしてある場所を追加していく.
    map<int, vector<int>> place;
    for (int i = 0; i < N; ++i) {
        place[a[i]].eb(i + 1);
    }

    //クエリ処理.
    while (Q--) {
        int x, k; cin >> x >> k; --k;

        //個数が足りてないなら終了.
        if (k >= (int)place[x].size()) {
            cout << -1 << endl;
            continue;
        }

        cout << place[x][k] << endl;
    }
    return 0;
}