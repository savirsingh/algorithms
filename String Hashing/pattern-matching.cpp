// code by savir singh

// Include everything needed for CP
#include <bits/stdc++.h>
using namespace std;

// Compiler Optimizations
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// Shorthand Macros
#define bit32 int32_t
#define int long long // comment out if unnecessary
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(a) (int) (a).size()
#define rsz resize
#define eb emplace_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define fe(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>n;i--)
#define fre(i,x,n) for(int i=x;i>=n;i--)
#define mod 1000000007
#define mod2 998244353
#define INF 1e18
#define ld long double
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define w(x) int x; fastscan(x); while(x--)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Fast Input
template<typename T, typename... Args>
inline void fastscan(T& num, Args&... args) {
    int c = getchar();
    num = 0;
    bool neg = false;

    // Handle negative numbers
    if (c == '-') {
        neg = true;
        c = getchar();
    }

    // Process digits
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar();
    }

    if (neg)
        num = -num;

    if constexpr (sizeof...(args) > 0)
        fastscan(args...); // Recursively read the remaining arguments
}

// Fast Output For Integers
inline void fastprint(int num, const string& endline = "\n") {
    if (num < 0) {
        putchar('-');
        num = -num;
    }
    char buffer[20];
    int idx = 19;
    buffer[idx--] = '\0';

    do {
        buffer[idx--] = static_cast<char>('0' + num % 10);
        num /= 10;
    } while (num > 0);

    fputs(&buffer[idx + 1], stdout);
    fputs(endline.c_str(), stdout);
}

// Fast Output for Strings
inline void fastprint(const string& s, const string& endline = "\n") {
    fputs(s.c_str(), stdout);
    fputs(endline.c_str(), stdout);
}

// String Hashing Template
const int A = 911382323; // A constant
const int B = 972663749; // B constant

class StringHash {
private:
    vector<long long> h; // Hash values of prefixes
    vector<long long> p; // Powers of A modulo B

public:
    StringHash(const string& s) {
        int n = s.size();
        h.resize(n);
        p.resize(n);

        h[0] = s[0];
        p[0] = 1;

        for (int i = 1; i < n; ++i) {
            h[i] = (h[i - 1] * A + s[i]) % B;
            p[i] = (p[i - 1] * A) % B;
        }
    }

    long long getHash(int a, int b) {
        if (a == 0) {
            return h[b];
        }

        return (h[b] - h[a - 1] * p[b - a + 1] % B + B) % B;
    }
};

vector<int> patternMatching(const string& s, const string& p) {
    int n = s.size();
    int m = p.size();

    StringHash hashS(s);
    StringHash hashP(p);

    long long hashPattern = hashP.getHash(0, m - 1);
    vector<int> occurrences;

    for (int i = 0; i <= n - m; ++i) {
        long long hashSubstring = hashS.getHash(i, i + m - 1);
        if (hashSubstring == hashPattern) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (s[i + j] != p[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                occurrences.push_back(i);
            }
        }
    }

    return occurrences;
}

bit32 main() {
    __

    string s = "ABABCABAB";
    string p = "AB";

    vector<int> occurrences = patternMatching(s, p);

    cout << "Pattern occurrences: ";
    for (int pos : occurrences) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
