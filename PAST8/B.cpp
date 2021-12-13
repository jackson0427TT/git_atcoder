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
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (int& x: A) cin >> x;
    for (int& x: B) cin >> x;

    //Aの要素でハッシュマップを作成.
    unordered_map<int, bool> exist;
    for (int& x: A) exist[x] = true;

    //Aに含まれるBの要素を抽出.
    set<int> st;
    for (int& x: A) if (exist[x]) st.insert(x);

    //出力.
    for (int& x: st) cout << x << " ";
    cout << endl;
    return 0;
}