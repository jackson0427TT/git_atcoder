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
    ll a, N; cin >> a >> N;

    //範囲を限ってbfs風に進行.
    ll x = 1, cnt = 0;
    queue<int> q, nex;
    q.push(x);
    vector<bool> seen(N * 10);
    while (q.size()) {
        //実行回数を更新.
        ++cnt;

        //次回分に送る.
        while (q.size()) {
            ll y = q.front(); q.pop();

            //a倍.
            if (y * a < N * 10 && !seen[y * a]) {
                seen[y * a] = true;
                nex.push(y * a);
            }

            //末尾を先頭に持って行ってみる.
            if (y >= 10 && y % 10) {
                ll fr = y % 10, ba = y / 10;
                string s = to_string(fr) + to_string(ba);
                ll pro = stoll(s);
                if (pro < N * 10 && !seen[pro]) {
                    seen[pro] = true;
                    nex.push(pro);
                }
            }
        }

        //更新完了作業.Nに到達していれば終了.
        while (nex.size()) {
            ll y = nex.front(); nex.pop();
            if (y == N) {
                cout << cnt << endl;
                return 0;
            }
            q.push(y);
        }
    }

    cout << -1 << endl;
    return 0;
}