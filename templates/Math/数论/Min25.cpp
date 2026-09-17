// 区间素数个数
ll n, st[N], primes[N], cnt, idx;
ll g[N], id1[N], id2[N], v[N];
// g(x), id1[x], id2[n / x], v[id1[x]] = x
// g[n][0] = \sum_{i} f(i), and f(1) = 0

ll get(ll x) { return x < N ? id1[x] : id2[n / x]; }
ll S(ll x) { return x; } // 零阶求和代表素数个数
ll f(ll x) { return 1; } // f(p) = 1

void init(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[ ++ cnt] = i; // primes[0] 占位
        for (int j = 1; i * primes[j] <= n; j ++ ) { // 因此从 1 开始
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    cin >> n; init(sqrt(n) + 1);
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        v[ ++ idx] = n / l;
        if (v[idx] < N) id1[v[idx]] = idx;
        else id2[n / v[idx]] = idx;
        g[idx] = (S(v[idx]) - 1);
    }
    for (int j = 1; j <= cnt; j ++ ) { // 因为 v 是从大到小存的，所以 dp 正序计算就不会重
        for (int i = 1; i <= idx && primes[j] * primes[j] <= v[i]; i ++ ) {
            g[i] = g[i] - f(primes[j]) * (g[get(v[i] / primes[j])] - g[get(primes[j - 1])]);
        }
    }
    cout << g[1] << "\n";
}