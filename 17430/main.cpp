#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_map<int, vector<int>> mp;

void Solve() {
    mp.clear();
    int n, x, y; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mp[x].push_back(y);
    }

    for (auto& p : mp) {
        sort(p.second.begin(), p.second.end());
    }

    for (auto& p1 : mp) {
        for (auto& p2 : mp) {
            if (p1.first == p2.first) {
                continue;
            }
            if (p1.second.size() != p2.second.size()) {
                cout << "NOT BALANCED\n";
                return;
            }
            for (int i = 0; i < p1.second.size(); i++) {
                if (p1.second.at(i) != p2.second.at(i)) {
                    cout << "NOT BALANCED\n";
                    return;
                }
            }
        }
    }
    cout << "BALANCED\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    while (T--) Solve();
}