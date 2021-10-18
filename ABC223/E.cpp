#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool can (ll X, ll Y, vector<ll> area) {
    for (int i = 0; i < 3; ++i) {
        if (X * Y < area[i]) continue;
        ll rx = X - (area[i] + Y - 1LL) / Y, ry = Y - (area[i] + X - 1LL) / X;
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            int k = 3 - i - j;
            if (rx * Y >= area[j]) {
                ll rrx = rx - (area[j] + Y - 1LL) / Y, rxry = Y - (area[j] + rx - 1LL) / rx;
                if (rrx * Y >= area[k] || rx * rxry >= area[k]) return true;
            }
            if (X * ry >= area[j]) {
                ll rry = ry - (area[j] + X - 1LL) / X, ryrx = X - (area[j] + ry - 1LL) / ry;
                if ((rry > 0 && X * rry >= area[k]) || (ryrx > 0 && ryrx * ry >= area[k])) return true;
            }
        }
    }
    return false;
}

int main() {
    ll X, Y; cin >> X >> Y;
    vector<ll> area(3);
    for (ll &x: area) cin >> x;
    cout << (can(X, Y, area) ? "Yes": "No") << endl;
}