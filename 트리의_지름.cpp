#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> t[100001];
int dp[100001], ans;
bool visited[100001];

int dfs(int curr) {
    int fst = 0, snd = 0, ret = dp[curr], tmp;
    visited[curr] = true;
    for (auto& p : t[curr]) {
        int next = p.first;
        if (!visited[next]) {
            dp[next] = dp[curr] + p.second;
            tmp = dfs(next);
            if (fst < tmp) {
                snd = fst;
                fst = tmp;
            } else if (snd < tmp) {
                snd = tmp;
            }
            ret = max(ret, tmp);
        }
    }
    ans = max(ans, fst + snd - 2 * dp[curr]);
    ans = max(ans, fst - dp[curr]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v; cin >> v;
    for (int i = 0; i < v; i++) {
        int a, b, c; cin >> a;
        while (1) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            t[a].emplace_back(b, c);
        }
    }
    dfs(1); cout << ans;
}