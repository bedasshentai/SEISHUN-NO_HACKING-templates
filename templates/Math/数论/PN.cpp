#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + (n))
const int N = 2e6 + 10, mod = 1e9 + 7, INf = 1e9;
int cnt, primes[N], st[N];
ll n, phi[N], g[N], ans;
unordered_map<ll, ll> _g, h[N];
// f(p^k) = p^k(p^k - 1)
// f[p] = g[p] = p*phi(p) = (1-p^2x)^-1*(1-px)
// p*phi(p) conv ID = ID_2

const ll inv2 = 500000004, inv6 = 166666668;

ll qpow(ll a, ll k = mod - 2) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

void init() {
    phi[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i, phi[i] = i - 1;
        for (int j = 0; j < cnt && i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j] % mod;
                break;
            }
            phi[i * primes[j]] = phi[i] * phi[primes[j]] % mod;
        }
    }
    for (int i = 1; i < N; i ++ ) g[i] = (i * phi[i] % mod + g[i - 1]) % mod;
    for (int i = 0; i < cnt; i ++ ) h[i][0] = 1, h[i][1] = 0; // this part is important
}

ll ID(ll x) {
    return (x % mod) * ((x + 1) % mod) % mod * inv2 % mod;
}

ll ID2(ll x) {
    return (x % mod) * ((x + 1) % mod) % mod * ((2 * x + 1) % mod) % mod * inv6 % mod;
}

ll get_g(ll n) { // Du sieve gets g's presum
    if (n < N) return g[n];
    if (_g.count(n)) return _g[n];
    ll res = ID2(n);
    for (ll l = 2, r; l <= n; l = r + 1)  {
        r = n / (n / l);
        res = (res - (ID(r) - ID(l - 1) + mod) % mod * get_g(n / l) % mod + mod) % mod;
    }
    return _g[n] = res;
}

void dfs_PN(int idx, ll now, ll val) { // idx-th prime, now = PN's value, val = h[now]
    (ans += get_g(n / now) * val % mod) %= mod;
    if (idx == cnt || now > n / primes[idx] / primes[idx]) return;
    for (int i = idx; i < cnt; i ++ ) {
        if (now > n / primes[i] / primes[i]) break;
        ll x = now * primes[i] * primes[i];
        for (int j = 2; x <= n; j ++ , x *= primes[i]) {
            if (!h[i].count(j)) { // replace it if h[i][j] is easy to calculate
                ll res = qpow(primes[i], j), res2 = 1ll * primes[i] * (primes[i] - 1) % mod; // f_j and g_0
                res = res * (res - 1) % mod; // g(1)h(p^j) = f(p^j) - \sigma:g(p^k)*h(p^(j-k))
                for (int k = 1; k <= j; k ++ ) {
                    res = (res - res2 * h[i][j - k] % mod + mod) % mod;
                    res2 = res2 * primes[i] % mod * primes[i] % mod;
                }
                h[i][j] = res;
            }
            if (h[i][j]) dfs_PN(i + 1, x, val * h[i][j] % mod);
        }
    }
}

void solve() {
    init();
    cin >> n;
    dfs_PN(0, 1, 1);
    cout << ans << "\n";
}