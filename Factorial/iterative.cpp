// code by savir singh
// only works up to 16! because of overflow.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int factorial(int n) {
    if (n%2==0) {
        ll f1=1;
        ll f2=1;
        for (int i=1; i<=n; i+=2) {
            f1 = (f1*i);
            f2 = (f2*(i+1));
        }
        ll f=f1*f2;
        return f;
    }
    else {
        ll f=1;
        for (int i=1; i<=n; i++) {
            f = f*i;
        }
        return f;
    }

}

int main()
{
    int x;
    cin >> x;
    cout << factorial(x);
}
