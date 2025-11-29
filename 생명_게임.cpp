#include <bits/stdc++.h>
using namespace std;

int n, m, t, k, a, b, dp[101][101];
bool mp[101][101];

int cnt(int r, int c) {
    int r1 = max(1, r-k), c1 = max(1, c-k);
    int r2 = min(n, r+k), c2 = min(m, c+k);
    return dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1] - mp[r][c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t >> k >> a >> b;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c; mp[i][j] = (c == '*');
        }
    }

    while (t--) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mp[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int tmp = cnt(i, j);

                if (mp[i][j] && (tmp < a || tmp > b)) {
                    mp[i][j] = false;
                } else if (!mp[i][j] && tmp > a && tmp <= b) {
                    mp[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (mp[i][j] ? '*' : '.');
        }
        cout << '\n';
    }
}