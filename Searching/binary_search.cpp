// code by savir singh
// efficient way to find element in vector

#include <bits/stdc++.h>
#define ll long long
#define del erase
using namespace std;

bool b_s(vector<int> v, int f)
{
    sort(v.begin(), v.end());
    int low = 0, high = v.size() - 1;
    int mid;
    while (high - low > 1) {
        int mid = (high+low) / 2;
        if (v[mid] < f) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    if (v[low]==f || v[high]==f) {
        true;
    }
    else {
        return false;
    }
}

int main()
{
    vector<int> example {1, 7, 2, 19, 2, 2};
    cout << b_s(example, 8);
}
