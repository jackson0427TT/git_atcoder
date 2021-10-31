#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N; cin >> N;

    vector<int> deg(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        ++deg[a];
        ++deg[b];
    }

    for (int i = 0; i < N; ++i) {
        if (deg[i] == N - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}