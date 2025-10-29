#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, n, m, k, parent[100001];

int find(int x) {
    if (x == parent[x]) {
        return x;    
    }
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int u = find(x);
    int v = find(y);
    
    if (u == v) return;

    if (u > v) {
        parent[v] = u;
    } else {
        parent[u] = v;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        if (i == k-1) {
            a = u;
        } else {
            Union(u, v);
        }
    }

    a = find(a);

    ll t1 = 0, t2 = 0;

    for (int i = 1; i <= n; i++) {
        if (a == find(i)) {
            t1++;
        } else {
            t2++;
        }
    }

    cout << t1 * t2;
}