// code by savir singh
// finds power in logarithmic time

#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    int ans = 1;
    while (b > 0) {
        if (b % 2 == 1) ans *= a;
        a *= a;
        b /= 2;
    }
    cout << ans << endl;
}
