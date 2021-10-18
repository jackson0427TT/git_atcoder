#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    double t = 0;
    vector<double> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        t += A[i] / B[i];
    }
    t /= 2.0;
    double ans = 0, now = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] / B[i] <= t - now) {
            ans += A[i];
            now += A[i] / B[i];
        }
        else {
            ans += B[i] * (t - now);
            break;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
}