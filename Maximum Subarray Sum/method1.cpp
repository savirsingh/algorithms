// code by savir singh
// Calculating the maximum subarray sum of a given array.
// Most efficient method - O(n)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maximum_subarray_sum(vector<int> arr, int n) {
    int maximum=0;
    int current=0;
    for (int i=0; i<n; i++) {
        current = max(arr[i], current+arr[i]);
        maximum = max(maximum, current);
    }
    return maximum;
}

int main()
{
    vector<int> example_array = {1, -2, 3, -4, 5, 6, 7, -6, -4, -2};

    cout << maximum_subarray_sum(example_array, example_array.size());
}
