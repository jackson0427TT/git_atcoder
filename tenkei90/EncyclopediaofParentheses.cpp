#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

/*
function::条件を満たす括弧列かの判断.
Order::par.size().
*/
bool ok(string par) {
    int cnt = 0;
    for (char c: par) {
        if (c == '(') ++cnt;
        else --cnt;
        //一度でも')'が多くなればアウト.
        if (cnt < 0) return false;
    }

    //括弧列が閉じ切ってなかったらアウト.
    return !cnt;
}

int main() {
    //入力.
    int N; cin >> N;

    //bit全探索で構築.辞書順出力のため一度setに格納.
    set<string> st;
    for (int b = 0; b < (1 << N); ++b) {
        //括弧列の構築.
        string par;
        for (int i = 0; i < N; ++i) {
            if (b & (1 << i)) par += '(';
            else par += ')';
        }

        //正規列かの確認.
        if (ok(par)) st.insert(par);
    }

    //出力.
    for (string s: st) cout << s << endl;
    return 0;
}