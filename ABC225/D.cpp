#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;

    vector<int> parent(N, -1), child(N, -1);
    for (int i = 0; i < Q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y; --x; --y;
            parent[y] = x;
            child[x] = y;
        }
        if (t == 2) {
            int x, y; cin >> x >> y; --x; --y;
            parent[y] = -1;
            child[x] = -1;
        }
        if (t == 3) {
            int x; cin >> x; --x;
            deque<int> q;
            q.push_back(x + 1);
            int now = x;
            while (parent[now] != -1) {
                q.push_front(parent[now] + 1);
                now = parent[now];
            }
            now = x;
            while (child[now] != -1) {
                q.push_back(child[now] + 1);
                now = child[now];
            }
            cout << q.size() << " ";
            while (q.size()) {
                cout << q.front() << " ";
                q.pop_front();
            }
            cout << endl;
        }
    }
    return 0;
}