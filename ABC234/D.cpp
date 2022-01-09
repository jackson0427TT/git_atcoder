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
    int N, K; cin >> N >> K;
    
    /*
    シュミレート.
    操作1::優先度付きキューにツッコむ.
    操作2::優先度付きキューのサイズをK以下にする.(大きい方からK個を保持.)
    操作3::優先度付きキューの先頭を出力.
    */
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < N; ++i) {
        //操作1.
        int p; cin >> p;
        q.push(p);

        //操作2.
        if (q.size() > K) q.pop();

        //操作3.
        if (i >= K - 1) cout << q.top() << endl;
    }
    return 0;
}