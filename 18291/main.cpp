#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
constexpr ll p = 1000000007;

ll fpow(ll x, int y, ll p) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % p;
        y >>= 1;  x = x * x % p;
    }
    return ret;
}

void Input() {
    cin >> n;
}

void Solution() {
    if (n == 1) {
        cout << 1 << '\n';
    } else {
        cout << fpow(2, n-2, p) << '\n';
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    
    while (T--) Solve();
}