#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;

/*
function::約数を全列挙して配列で返す.昇順に整理済み.
Order::√N
*/
template<typename T>
vector<T> divisor(T x) {
    vector<T> ret;
    stack<T> st;
    
    //約数全列挙.
    for (T a = 1; a * a <= x; ++a) {
        if (x % a) continue;
        ret.eb(a);
        if (a * a != x) st.push(x / a); //√xの二重格納は回避.
    }

    while (st.size()) {
        ret.eb(st.top()); st.pop();
    }

    return ret;
}

int main() {
    //入力.
    int X, Y; cin >> X >> Y;

    //約数全列挙.
    vector<int> x = divisor(X), y = divisor(Y);

    //出力.
    if (x.size() == y.size()) cout << 'Z' << endl;
    else cout << (x.size() > y.size() ? 'X': 'Y') << endl;
    return 0;
}

/*
P.S.
実際にはX,Y<=10^6なので,全て試す余裕がある.
*/