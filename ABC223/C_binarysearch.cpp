#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double calc_time (double d, const vector<double> &A, const vector<double> &B) {
    double ret = 0, it = 0, now = 0;
    while (now + A[it] <= d) {
        ret += A[it] / B[it];
        now += A[it]; ++it;
    }
    ret += (d - now) / B[it];
    return ret;
}

double BinarySearch (double l, double r, double t, const vector<double> &A, const vector<double> &B) {
    for (int i = 0; i < 100; ++i) {
        double m = (l + r) / 2.0, tr = calc_time(m, A, B);
        if (tr <= t / 2.0) l = m;
        else r = m;
    }
    return l;
}

int main() {
    int N; cin >> N;
    double len = 0, t = 0;
    vector<double> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        len += A[i];
        t += A[i] / B[i];
    }

    double ans = BinarySearch(0, len, t, A, B);

    cout << fixed << setprecision(15) << ans << endl;
}
