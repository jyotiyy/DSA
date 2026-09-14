/*  ॐ  */

#include <bits/stdc++.h>
using namespace std;

/* ==================== FAST I/O ==================== */

#define BRUH ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

/* ==================== TYPEDEFS ==================== */

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using vi  = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;

/* ==================== CONSTANTS ==================== */

constexpr int INF = 1e9;
constexpr ll LINF = 1e18;
constexpr ll MOD = 998244353;          // Change if needed

/* ==================== SHORTCUTS ==================== */

#define pb push_back
#define all(x) (x).begin(), (x).end()

#define YES cout << "YES\n"
#define NO  cout << "NO\n"

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define forl(i, a, b) for (ll i = (a); i <= (b); i++)
#define forr(i, a, b) for (ll i = (a); i >= (b); i--)

/* ==================== MODULAR ARITHMETIC ==================== */

// Fast exponentiation: a^b % MOD
ll modPow(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;

    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}

// Modular Multiplicative Inverse (MOD must be prime)
ll modInv(ll a, ll m = MOD) {
    return modPow(a, m - 2, m);
}

/* ==================== SOLUTION ==================== */

void solve() {

}

/* ==================== MAIN ==================== */

int main() {
    BRUH;

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}
