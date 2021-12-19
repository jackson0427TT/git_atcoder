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
    string S; cin >> S;

    //文字列から数字を受け取り,int型に変換.
    int a = S[0] - '0', b = S[2] - '0';

    //出力.
    cout << a * b << endl;
    return 0;
}