#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int X; cin >> X;
    if (X) {
        cout << (X % 100 ? "No": "Yes") << endl;
    }
    else cout << "No" << endl;
}