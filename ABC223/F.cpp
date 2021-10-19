#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1e9;

int op(int a, int b) {return min(a, b);}
int e() {return INF;}
int mapping(int f, int x) {return f + x;}
int composition(int f, int g) {return f + g;}
int id() {return 0;}

int main() {
    int N, Q; string S; cin >> N >> Q >> S;
    vector<int> sum(N + 1);
    for (int i = 0; i < N; ++i) {
        sum[i + 1] = sum[i] + (S[i] == '(' ? 1: -1);
    }
    lazy_segtree<int, op, e, int, mapping, composition, id> lt(sum);
    for (int i = 0; i < Q; ++i) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            if (S[l - 1] == S[r - 1]) continue;
            if (S[l - 1] == '(') {
                lt.apply(l, r, -2);
            }
            else {
                lt.apply(l, r, 2);
            }
            swap(S[l - 1], S[r - 1]);
        }
        else {
            if (lt.prod(l - 1, r + 1) == lt.get(l - 1) && lt.get(l - 1) == lt.get(r)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}