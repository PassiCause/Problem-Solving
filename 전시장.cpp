#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
/*
순서대로 나열했을 때, 관람객은 높이 때문에 일부만 보임
S 이상 노출된 경우에만 관람객들이 삼

길이가 S 이상 노출된 그림들의 가격의 합의 최댓값은?


*/

vector<pii> v;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s; cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int h, c; cin >> h >> c; v.emplace_back(h, c);
    }

    sort(v.begin(), v.end());

    
}