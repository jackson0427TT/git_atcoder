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
    vector<ll> A(N);
    for (ll& x: A) cin >> x;

    //素因数2の部分と残りの部分に分ける.
    int two = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < N; ++i) {
        while (!(A[i] & 1)) {
            ++two;
            A[i] >>= 1;
        }
        q.push(A[i]);
    }

    //最小値を貪欲に最大化.
    while (two) {
        ll now = q.top(); q.pop();
        while (two && now <= q.top()) {
            --two;
            now *= 3LL;
        }
        q.push(now);
    }

    //出力.
    cout << q.top() << endl;
    return 0;
}