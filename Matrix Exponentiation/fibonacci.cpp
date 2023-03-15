// code by savir singh

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

struct Matrix {
    int mat[2][2];
    Matrix operator *(Matrix other)  {
        Matrix product{{{0, 0}, {0, 0}}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    product.mat[i][k] += mat[i][j] * other.mat[j][k];
                    product.mat[i][k] %= MOD;
                }
            }
        }
        return product;
    }
};

Matrix matPow(Matrix a, int b) {
    Matrix res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res.mat[i][j] = (i == j);
            }
        }
    }
    while (b) {
        if (b % 2 == 1) res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}

int fib(int n) {
  Matrix f;
  f.mat[0][0] = 0;
  f.mat[0][1] = f.mat[1][0] = f.mat[1][1] = 1;

  f = matPow(f, n);

  return f.mat[0][1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << fib(n) << endl;
}
