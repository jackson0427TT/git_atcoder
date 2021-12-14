#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

template<typename T>
vector<T> compress(vector<T> &X){
    map<T, int> mp;
    for(T &x: X)mp[x] = 0;
    int id = 1;
    for(auto &p: mp)p.second = id++;
    vector<T> ret;
    for(T &x: X)ret.push_back(mp[x]);
    return ret;
}

int main() {
    //入力.
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int& x: A) cin >> x;
    for (int& x: B) cin >> x;

    //Bに関して座標圧縮.
    vector<int> Bcom = compress(B);

    //ギフトを構築し、Aで昇順ソート.(Bは降順になるよう負にする.)
    vector<P> gift(N);
    for (int i = 0; i < N; ++i) gift[i] = {A[i], -Bcom[i]};
    sort(gift.begin(), gift.end());

    //BITでBの値を管理しながら探索.
    ll ans = 0, it = 0;
    fenwick_tree<ll> fen(N + 1);
    /*
    ループ内の機能.
    1: gift[i].first以下のgift[j].first全てをBITに追加.
    2: BIT内のgift[i].second以下の要素を加える.
    */
    for (int i = 0; i < N; ++i) {
        //1
        while (it < N && gift[it].fi == gift[i].fi) {
            //gift[it]の要素をBITに加算.
            int b = gift[it].se + N;
            fen.add(b, 1);
            ++it;
        }

        //2
        ans += fen.sum(0, gift[i].se + N + 1);
    }

    //出力.
    cout << ans << endl;
    return 0;
}