#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll, ll>
const int N = 1e5;
ll n, k;
ll primes[N], st[N], mu[N], cnt;
unordered_map<ll, ll> summu;

// precalculate Mu
void init_mu() {
    mu[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i, mu[i] = -1;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 2; i < N; i ++ ) mu[i] += mu[i - 1];
}

ll get_mu(ll n) {
    if (n < N) return mu[n];
    if (summu.count(n)) return summu[n];
    ll res = 1;
    for (ll l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l);
        res -= (r - l + 1) * get_mu(n / l);
    }
    return summu[n] = res;
}

ll f(ll a, ll b, ll c, ll n) {
	if (!a) return b / c * (n + 1);
	if (a < c && b < c) {
		ll m = (a * n + b) / c;
		if (!m) return 0;
		return n * m - f(c, c - b - 1, a, m - 1);
	}
	return f(a % c, b % c, c, n) + (n + 1) * n / 2 * (a / c) + (n + 1) * (b / c);
}

// O(logn) calculate next one by one
PII nxt_fraction(ll n, PII fac) {
    ll a = fac.first, b = fac.second, c, d;
    exgcd(b, a, c, d);
    d = -d;
    if (d <= 0) {
        ll k = (-d + b - 1) / b;
        c += k * a;
        d += k * b;
    }
    ll k = (n - d) / b;
    return {c + k * a, d + k * b};
}

// O(1) calculate next one by two nearly
PII nxt_fraction(ll n, PII fac1, PII fac2) {
    auto [a, b] = fac1;
    auto [c, d] = fac2;
    return {(n + b) / d * c - a, (n + b) / d * d - b};
}

// O(sqrt(n)logn) calculate fraction's rank
ll fraction_to_rank(ll n, PII fac) {
    ll res = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        res += (get_mu(r) - get_mu(l - 1)) * f(fac.first, 0, fac.second, n / l);
    }
    return res;
}

// O(sqrt(n)log(n)^2) calculate the fraction of k-th rank
PII rank_to_fraction(ll n, ll k) {
    ll l = 0, r = n;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (fraction_to_rank(n, {mid, n}) <= k) l = mid;
        else r = mid - 1;
    }
    k -= fraction_to_rank(n, {r, n});
    PII a = {r / __gcd(r, n), n / __gcd(r, n)}, b = nxt_fraction(n, a);
    if (!k) return a;
    while (k -- ) a = nxt_fraction(n, a, b), swap(a, b);
    return a;
}

void solve() {
    cin >> n;
    PII now = {1, n};
    while (now.first != now.second) {
        ll rk = fraction_to_rank(n, now);
        PII fac = rank_to_fraction(n, rk);
        cout << rk << " : " << fac.first << " " << fac.second << " | " << now.first << " " << now.second << "\n";
        now = nxt_fraction(n, now);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init_mu();
    int T = 1;
    // cin >> T;
    while (T -- ) solve();
    return 0;
}