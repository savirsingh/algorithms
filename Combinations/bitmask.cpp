#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mask; cin >> n;
    set<vector<int>> comb;
    for (int i = 0; i <= 1 << n; i++) {
        vector<int> choose;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) choose.push_back(j + 1);
        }
        comb.insert(choose);
    }
    for (auto i : comb) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}
