int inv[N << 1], inv_len;

void inv_init(int n) {
    if (n <= inv_len) return;
    if (!inv_len) inv[0] = inv[1] = 1, inv_len = 1;
    for (int i = inv_len + 1; i <= n; i ++ ) inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
    inv_len = n;
}

void Poly_d(int *f, int n) {
    for (int i = 1; i < n; i ++ ) f[i - 1] = 1ll * f[i] * i % mod;
    f[n - 1] = 0;
}

void Poly_int(int *f, int n) {
    for (int i = n; i; i -- ) f[i] = 1ll * f[i - 1] * inv[i] % mod;
    f[0] = 0;
}