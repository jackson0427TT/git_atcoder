#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

bool judge(int N, vector<int>& s, vector<int>& t) {
    if (s.size() != t.size()) return false;
    int sx0 = s[0] / N, sy0 = s[0] % N;
    int tx0 = t[0] / N, ty0 = t[0] % N;
    int dx = tx0 - sx0, dy = ty0 - sy0;
    for (int i = 0; i < s.size(); ++i) {
        int sx = s[i] / N, sy = s[i] % N;
        int tx = t[i] / N, ty = t[i] % N;
        if (sx + dx != tx || sy + dy != ty) return false;
    }
    return true;
}

vector<string> Rotate90(vector<string> S) {
    int N = S.size();
    vector<string> ret(N);
    for (int j = N - 1; j >= 0; --j) {
        string s;
        for (int i = 0; i < N; ++i) {
            s += S[i][j];
        }
        ret[N - 1 - j] = s;
    }
    return ret;
}

int main() {
    int N; cin >> N;
    vector<string> S(N), T(N);
    for (string& s: S) cin >> s;
    for (string& s: T) cin >> s;

    for (int t = 0; t < 4; ++t) {
        vector<int> s_pos, t_pos;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int pos = i * N + j;
                if (S[i][j] == '#') {
                    s_pos.emplace_back(pos);
                }
                if (T[i][j] == '#') {
                    t_pos.emplace_back(pos);
                }
            }
        }

        if (judge(N, s_pos, t_pos)) {
            cout << "Yes" << endl;
            return 0;
        }

        S = Rotate90(S);
    }
    cout << "No" << endl;
}