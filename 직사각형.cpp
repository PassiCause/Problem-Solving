#include <bits/stdc++.h>
using namespace std;

int p[10000];

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p+n, greater<int>());

    for (int i = 0; i < n-1; i++) {
        if (p[i] - p[i+1] <= 1) {
            v.push_back(p[++i]);
        }
    }
    reverse(v.begin(), v.end());

    long long ans = 0;

    while (v.size() > 1) {
        long long a = v.back();
        v.pop_back();
        long long b = v.back();
        v.pop_back();

        ans += a * b;
    }
    cout << ans;
}