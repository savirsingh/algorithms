// code by savir singh

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+2;

int n, a[MAX], dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n] << endl;
}
