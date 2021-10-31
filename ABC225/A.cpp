#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    string s; cin >> s;
    
    set<char> st;
    for (char c: s) st.insert(c);

    int n = st.size();
    if (n == 1) cout << 1 << endl;
    else if (n == 2) cout << 3 << endl;
    else cout << 6 << endl;
    return 0;
}