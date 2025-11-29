#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

typedef pair<int, int> pii;

int n, m, x, ans;
vector<pii> graph[1001];

int djikstra(int from, int to) {
    int dp[1001];
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    dp[from] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({ 0, from }); 

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();

        int current_distance = top.first;
        int current_location = top.second;

        for (pii& p : graph[current_location]) {
            int next_distance = current_distance + p.second;
            int next_location = p.first;

            if (next_distance < dp[next_location]) {
                dp[next_location] = next_distance;
                pq.push({ next_distance, next_location });
            }
        }
    }
    return dp[to];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;

        graph[a].emplace_back(b, t);
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, djikstra(i, x) + djikstra(x, i));
    }

    cout << ans;
}