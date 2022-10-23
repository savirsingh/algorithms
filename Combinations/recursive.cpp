// code by savir singh
// Bruce's algorithm
// getting all combinations of 1-n

#include <bits/stdc++.h>
using namespace std;
// macros
#define int long long
#define double long double
#define bit32 int32_t
#define del erase
#define pb push_back
#define str string
#define scani(x) scanf("%lld", &x)
#define scan(x) scanf("%s", &x)
#define scanc(x) scanf("%c", &x)
#define printi(x) printf("%lld", x);
#define print(x) printf("%s", x);
#define printc(x) printf("%c", x);
#define pii pair<int, int>

// all vars
int n;

// combinations function
void func(int i, vector<int>& comb){
    if(i > n) {
        cout << "(";
        for(int x : comb) cout << x << ",";
        cout << ")\n"; return;
    }
    func(i+1, comb); //don't choose i
    comb.push_back(i); func(i+1, comb); comb.pop_back(); //choose i
}

// driver code
bit32 main(){
    cin >> n; vector<int> comb;
    func(1, comb);
}
