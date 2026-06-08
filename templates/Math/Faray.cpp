#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll, ll>
const int N = 2e6 + 10;
ll n;
ll primes[N], st[N], mu[N], cnt;

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
}

// O(n + logn) calculate next one by one
PII nxt_fraction(PII fac) {
    ll l = 0, r = n;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (mid * fac.second <= n * fac.first) l = mid;
        else r = mid - 1;
    }
    PII res = {r + 1, n};
    for (int i = 1; i <= n; i ++ ) {
        PII fac_i = {((r + 1) * i - 1) / n, i};
        if (fac_i.first * fac.second <= fac_i.second * fac.first) continue;
        if (fac_i.first * res.second < fac_i.second * res.first) res = fac_i;
    }
    ll d = __gcd(res.first, res.second);
    return {res.first / d, res.second / d};
}

// O(1) calculate next one by two nearly
PII nxt_fraction(PII fac1, PII fac2) {
    auto [a, b] = fac1;
    auto [c, d] = fac2;
    return {(n + b) / d * c - a, (n + b) / d * d - b};
}

ll fraction_to_rank(PII fac) {
    static ll A[N];
    for (int i = 1; i <= n; i ++ ) A[i] = fac.first * i / fac.second + A[i - 1];
    ll res = 0;
    for (int i = 1; i <= n; i ++ ) res += mu[i] * A[n / i];
    return res;
}

PII rank_to_fraction(ll k) {
    ll l = 0, r = n;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (fraction_to_rank({mid, n}) <= k) l = mid;
        else r = mid - 1;
    }
    k -= fraction_to_rank({r, n});
    PII a = {r / __gcd(r, n), n / __gcd(r, n)}, b = nxt_fraction(a);
    if (!k) return a;
    while (k -- ) a = nxt_fraction(a, b), swap(a, b);
    return a;
}

void solve() {
    cin >> n;
    PII now = {1, n};
    while (now.first != now.second) {
        ll rk = fraction_to_rank(now);
        PII fac = rank_to_fraction(rk);
        cout << rk << " : " << fac.first << " " << fac.second << " | " << now.first << " " << now.second << "\n";
        now = nxt_fraction(now);
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