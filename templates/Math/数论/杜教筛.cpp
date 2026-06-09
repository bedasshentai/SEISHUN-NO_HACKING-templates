ll get_sum(ll n) {
    if (n < N) return pref[n]; // 预处理的前缀和
    if (sumf[n]) return sumf[n]; // 哈希存储前缀和
    ll res = get_sum(n); // f * g 的前缀和
    for (ll l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l);
        res -= get_g(l, r) * get_sum(n / l); // g(l ~ r) * S(n / l)
    }
    return sumf[n] = res;
}