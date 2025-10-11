#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p1[1025], p2[1025], ans;
ll n,p,a[200000],b[200000];
vector<pair<pair<ll, ll>, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>p;

    for (int i=0;i<n;i++){
        int a; cin >> a; p1[a]++;
    }
    for (int i=0;i<n;i++){
        int b; cin >> b; p2[b]++;
    }
    for (int i = 0; i <= 1024; i++) {
        for (int j = 0; j <= 1024; j++) {
            v.push_back({ { i, j }, (i | j) - (i ^ j) });
        }
    }
    sort(v.begin(), v.end(), [&](pair<pair<ll, ll>, ll> x, pair<pair<ll, ll>, ll> y) {
        return x.second > y.second;
    });
    for (int i = 0; i <= 1024; i++) {
        for (int j = 0; j <= 1024; j++) {
            ans += (i ^ j) * p1[i] * p2[j];
        }
    }
    for (auto& [fst, snd] : v) {
        ll t = min(p1[fst.first] * p2[fst.second], p);
        ans += t * snd; p -= t;
    }
    cout << ans;
}