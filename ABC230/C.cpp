#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

struct cross_grid {
    //クロスの中心位置を定める.
    ll cx, cy;
    
    cross_grid(ll a, ll b): cx(a), cy(b) {}

    //黒く塗られたクロス上かの判定.
    bool color_of_cell(ll x, ll y) {
        ll dx = abs(x - cx), dy = abs(y - cy);
        return dx == dy;
    }
    //function::gridにおける指定範囲の様相をコピーする.
    vector<string> copy(ll sx, ll fx, ll sy, ll fy) {
        vector<string> ret(fx - sx + 1LL);
        for (ll x = sx; x <= fx; ++x) {
            //特定の行に対する結果の一時保存.
            string line;
            for (ll y = sy; y <= fy; ++y) {
                if (color_of_cell(x, y)) line += '#';
                else line += '.';
            }

            ret[x - sx] = line;
        }
        return ret;
    }
};

int main() {
    //入力.
    ll N, A, B; cin >> N >> A >> B;
    cross_grid grid(A, B);
    ll P, Q, R, S; cin >> P >> Q >> R >> S;

    //結果をコピー.
    vector<string> ans = grid.copy(P, Q, R, S);

    for (string s: ans) cout << s << endl;
    return 0;
}