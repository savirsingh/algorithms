// code by savir singh

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e6+2;

int n, a[MAX];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> lis;
    lis.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] > lis[lis.size()-1] || lis.empty()) lis.push_back(a[i]);
        else {
            int index = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            if (index == lis.size()-1) lis[index] = a[i];
        }
    }
    cout << "LIS length: " << lis.size() << endl;
    cout << "LIS: ";
    for (auto x : lis) cout << x << " ";
    cout << endl;
}
