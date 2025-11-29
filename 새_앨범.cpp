#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, c; cin >> n >> l >> c;

    int t = min(n, (c-l)/(l+1)+1);

    if (t % 13 == 0) {
        t -= 1;
    }
    // cout << t << '\n';
    // cout << n % t << '\n';
    // cout << (n%t!=0&&n%t%13==0) << '\n';
    
    int ans = (int)ceil((double)n/t);
    // cout << t << ' ' << ans << '\n';
    //  + (n%t!=0&&n%t%13==0);
    if (n%t!=0&&n%t%13==0&&t-n%t==1) ans += 1;

    cout << ans;
    
}