#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;

    string S_max = S, S_min = S;
    for (int i = 0; i < S.size() - 1; ++i) {
        string nex = S.substr(1) + S[0];
        S_max = max(S_max, nex);
        S_min = min(S_min, nex);
        S = nex;
    }

    cout << S_min << "\n" << S_max << endl;
}