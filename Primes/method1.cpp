// code by savir singh
// A function to check if a given number is prime.
// (Method 1)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check_prime(int num) {
    if(num==0 || num==1) {
        return false;
    }
    for (int i=2; i<pow(num, 0.5)+1; i++) {
        if (num%i==0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int number;
    cin >> number;
    cout << check_prime(number);
}
