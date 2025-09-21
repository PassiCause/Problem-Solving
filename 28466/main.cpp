#include <bits/stdc++.h>
using namespace std;

int a[10][10], b[12][12];

vector<int> p[10][12];
vector<pair<int, int>> v;

void solve() {
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int x;
        char s[3];

        cin >> x >> s;

        s[0] -= '0';
        s[1] -= 'A';

        p[s[0]][s[1]].push_back(x);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            sort(p[i][j].begin(), p[i][j].end(), greater<int>());
        }
    }

    for (int i = 0; i < 10; i++) for (int j = 0; j < 12; j++) v.push_back({ i, j });

    for (int x = 0; x < v.size(); x++) for (int y = x; y < v.size(); y++) for (int z = y; z < v.size(); z++) {
        int xx = v[x].first, xy = v[x].second;
        int yx = v[y].first, yy = v[y].second;
        int zx = v[z].first, zy = v[z].second;        
        int tmp = 0;
        if (x == y && y == z) {
            if (p[xx][xy].size() < 3) continue;
            tmp += p[xx][xy][0];
            tmp += p[xx][xy][1];
            tmp += p[xx][xy][2];
        } 
        else if (x == y) {
            if (p[xx][xy].size() < 2 || p[zx][zy].empty()) continue;
            tmp += p[xx][xy][0];
            tmp += p[yx][yy][1];
            tmp += p[zx][zy][0];
        }
        else if (y == z) {
            if (p[yx][yy].size() < 2 || p[xx][xy].empty()) continue;
            tmp += p[xx][xy][0];
            tmp += p[yx][yy][0];
            tmp += p[zx][zy][1];
        }
        else {
            if (p[xx][xy].empty() || p[yx][yy].empty() || p[zx][zy].empty()) continue;
            tmp += p[xx][xy][0];
            tmp += p[yx][yy][0];
            tmp += p[zx][zy][0];
        }
        tmp += a[xx][yx] + a[yx][zx] + a[zx][xx];
        tmp += b[xy][yy] + b[yy][zy] + b[zy][xy];
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--) solve();
}