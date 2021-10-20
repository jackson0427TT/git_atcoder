#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

vector<vector<int>> compress(vector<int>& x, vector<int>& y) {
    vector<vector<int>> ret;
    
    map<int, vector<int>> x_axis;
    for (int i = 0; i < x.size(); ++i) {
        x_axis[x[i]].emplace_back(y[i]);
    }

    for (auto mp: x_axis) {
        vector<int> v = mp.second;
        sort(v.begin(), v.end());
        ret.emplace_back(v);
    }

    return ret;
}

int main() {
    int N; cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

    vector<vector<int>> g = compress(x, y);

    int M = g.size();
    ll ans = 0;
    for (int i = 0; i < M - 1; ++i) {
        for (int j = i + 1; j < M; ++j) {
            int ii = 0, ij = 0, i_lim = g[i].size(), j_lim = g[j].size();
            ll cnt = 0;
            while (ii < i_lim && ij < j_lim) {
                if (g[i][ii] == g[j][ij]) {
                    ++cnt; ++ii; ++ij;
                    continue;
                }
                if (g[i][ii] < g[j][ij]) ++ii;
                else ++ij;
            }
            ans += cnt * (cnt - 1) / 2LL;
        }
    }

    cout << ans << endl;
}