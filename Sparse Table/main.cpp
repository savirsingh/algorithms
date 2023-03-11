// code by savir singh
// for range minimum query

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5;
// i<<j = 2^j

int n, k, sparse[20][MAX], a[MAX], lg[MAX];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    lg[1] = 0;
    for (int i = 2; i <= MAX; i++) {
        lg[i] = lg[i/2]+1;
    }
    for (int i = 1; i <= n; i++) {
        sparse[0][i] = a[i];
    }
    for (int i = 1; i <= lg[n]; i++) {
        for (int j = 1; j + (1 << i) <= n + 1; j++) {
            sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
        }
    }
    for (int i = 1, l, r; i <= k; i++) {
        cin >> l >> r;
        int j = lg[r-l+1];
        cout << min(sparse[j][l], sparse[j][r-(1<<j)+1]) << endl;
    }
}
