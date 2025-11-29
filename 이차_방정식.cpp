#include <bits/stdc++.h>
using namespace std;

long long k, t;
map<long long, long long> mp;

int main() {
    cin >> k; t = abs(k);

    for (int i = 2; i * i <= t; i++) {
        while (t % i == 0) {
            mp[i]++; t /= i;
        }
    }
    int ret = 1;
    for (auto& p : mp)
        ret *= p.second * 2 + 1;
    if (t > 1) {
        ret *= 3;   
    }
    ret += 1;

    cout << ret << ' ' << ret * 2 * k; 
}