#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    string ans;
    for (int i = 0; i < 26; ++i) {
        int x; cin >> x;
        ans += (char)('a' + (x - 1));
    }
    cout << ans << endl;
}