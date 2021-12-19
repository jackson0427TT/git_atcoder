#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main() {
    //入力.
    int N, M; cin >> N >> M;
    vector<P> e1(M), e2(M);
    for (int i = 0; i < M; ++i) {
        cin >> e1[i].fi >> e1[i].se;
        if (e1[i].fi > e1[i].se) swap(e1[i].fi, e1[i].se);
    }
    for (int i = 0; i < M; ++i) {
        cin >> e2[i].fi >> e2[i].se;
        --e2[i].fi; --e2[i].se;
    }

    //辺の構成が同じかどうかを確認しやすくするためにソートしておく.
    sort(e1.begin(), e1.end());

    //順列全探索.
    vector<int> arr(N);
    iota(arr.begin(), arr.end(), 1);
    do {
        //cor::e2をarrの対応に合わせて変換したもの.
        vector<P> cor(M);
        for (int i = 0; i < M; ++i) {
            cor[i].fi = arr[e2[i].fi];
            cor[i].se = arr[e2[i].se];
            if (cor[i].fi > cor[i].se) swap(cor[i].fi, cor[i].se);
        }
        sort(cor.begin(), cor.end());

        //確認.
        if (e1 == cor) {
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(arr.begin(), arr.end()));

    //作成不可能だった場合.
    cout << "No" << endl;
    return 0;
}