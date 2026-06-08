typedef long long ll;
const ll mod = 998244353, inv2 = 499122177, inv6 = 166374059;
ll a, b, c, n;
struct Node {
    ll f, g, h;
};

Node solve(ll a, ll b, ll c, ll n) {
    Node ans, tmp;
    if (!a) return (Node){(b / c) * (n + 1) % mod, (b / c) * (b / c) % mod * (n + 1) % mod, (b / c) * n % mod * (n + 1) % mod * inv2 % mod};
    if (a < c && b < c) {
        ll m = (a * n + b) / c;
        if (!m) return (Node){0, 0, 0};
        tmp = solve(c, c - b - 1, a, m - 1);
        m %= mod;
        ans.f = (m * n % mod - tmp.f + mod) % mod;
        ans.g = ((m * (m + 1) % mod * n % mod - 2 * tmp.h - 2 * tmp.f - ans.f) % mod + mod) % mod;
        ans.h = ((m * n % mod * (n + 1) % mod - tmp.f - tmp.g) % mod + mod) % mod * inv2 % mod;
        return ans;
    }
    tmp = solve(a % c, b % c, c, n);
    ans.f = (tmp.f + n * (n + 1) % mod * inv2 % mod * (a / c) % mod + (n + 1) * (b / c) % mod) % mod;
    ans.g = (tmp.g + (a / c) * (a / c) % mod * n % mod * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod + (n + 1) * (b / c) % mod * (b / c) % mod + 2 * (a / c) % mod * tmp.h % mod + 2 * (b / c) * tmp.f % mod + 2 * (a / c) * (b / c) % mod * n % mod * (n + 1) % mod * inv2 % mod) % mod;
    ans.h = (tmp.h + (a / c) * n % mod * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod + (b / c) * n % mod * (n + 1) % mod * inv2 % mod) % mod;
    return ans;
}