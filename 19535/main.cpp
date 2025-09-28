#include <bits/stdc++.h>
using namespace std;

vector<int> p[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, d = 0, z = 0;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        p[u].push_back(v);
        p[v].push_back(u);
    }

    for (int cur = 1; cur <= n; cur++) {
        size_t s1 = p[cur].size();
        if (s1 >= 3) {
            z += s1 * (s1 - 1) * (s1 - 2) / 6;
        }
        for (int nxt : p[cur]) {
            size_t s2 = p[nxt].size();
            if (nxt > cur) {
                d += (s1 - 1) * (s2 - 1);
            }
        }`
    }

    if (d > z * 3) {
        cout << "D";
    }
    if (d < z * 3) {
        cout << "G";
    }
    if (d == z * 3) {
        cout << "DUDUDUNGA";
    }
}