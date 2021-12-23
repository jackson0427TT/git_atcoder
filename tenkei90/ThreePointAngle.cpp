#include<bits/stdc++.h>
#include<atcoder/all>

#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<double, int>;

//二次元座標の点の位置情報.
struct point {
    double x, y;
    point(): x(0), y(0) {}
    point(double x, double y): x(x), y(y) {}
    
};
point operator-(const point& a, const point& b) {
    return point(a.x - b.x, a.y - b.y);
}
bool operator==(const point& a, const point& b) {
    return a.x == b.x && a.y == b.y;
}
//ある"ベクトル"の偏角.
double getangle(const point& p) {
    if (p.y >= 0) {
        double ret = atan2(p.y, p.x) * 180.0 / M_PI;
        return ret;
    }
    else {
        double ret = 360.0 + atan2(p.y, p.x) * 180.0 / M_PI;
        return ret;
    }
}

//2点取った時の間の角.
double getangle2(double a1, double a2) {
    double ret = abs(a1 - a2);
    if (ret > 180.0) ret = 360.0 - ret;
    return ret;
}

//ある点pに対して2点選んで偏角差を求めた時の最大値を返す.
double solve(point& p, vector<point>& v) {
    double ret = 0;
    vector<double> ang;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == p) continue;
        ang.eb(getangle(v[i] - p));
    }
    sort(ang.begin(), ang.end());
    for (int i = 0; i < ang.size(); ++i) {
        double oppo = ang[i] + 180.0;
        if (oppo > 360.0) oppo -= 360.0;
        auto it = lower_bound(ang.begin(), ang.end(), oppo) - ang.begin();
        int j = (it ? it - 1: ang.size() - 1), k = (it == ang.size() ? 0: it);
        ret = max(ret, getangle2(ang[i], ang[j]));
        ret = max(ret, getangle2(ang[i], ang[k]));
    }
    return ret;
}

int main() {
    int N; cin >> N;
    vector<point> pos(N);
    for (auto& a: pos) cin >> a.x >> a.y;

    double ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, solve(pos[i], pos));
    }

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}