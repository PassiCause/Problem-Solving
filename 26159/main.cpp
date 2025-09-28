#include <bits/stdc++.h>
using namespace std;

long long n, dp[100001];
vector<long long> graph[100001], r, a;

void Input() {
    // freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n - 1; i++) {
        int t; cin >> t; a.push_back(t);
    }
}

long long dfs(int cur) {
    dp[cur] = 1;

    for (int next : graph[cur]) {
        if (!dp[next]) {
            dp[cur] += dfs(next);
        }
    }
    return dp[cur];
}

void Solution() {
    dfs(1);
    for (int i = 2; i <= n; i++) {
        r.push_back(dp[i] * (n - dp[i]));
        // cout << dp[i] << '\n';
    }

    sort(a.rbegin(), a.rend());
    sort(r.begin(), r.end());

    long long ret = 0;

    for (int i = 0; i < n-1; i++) {
        ret = (ret + a[i] * r[i]) % 1000000007;
    }
    cout << ret;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solve();
}