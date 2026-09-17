void FWT_or(int *f, int op, int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                if (~op) (f[i | j | k] += f[i | j]) %= mod;
                else (f[i | j | k] += mod - f[i | j]) %= mod;
            }
        }
    }
}

void FWT_and(int *f, int op, int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                if (~op) (f[i | j] += f[i | j | k]) %= mod;
                else (f[i | j] += mod - f[i | j | k]) %= mod;
            }
        }
    }
}

void FWT_xor(int *f, int op, int n) {
    ll inv2 = (~op ? 1 : qpow(2));
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                int x = f[i | j], y = f[i | j | k];
                f[i | j] = (x + y) * inv2 % mod;
                f[i | j | k] = (mod + x - y) * inv2 % mod;
            }
        }
    }
}

void px(int *f, int *g, int n) {
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * g[i] % mod;
}

void print(int *f, int n) {
    for (int i = 0; i < n; i ++ ) cout << f[i] << " \n"[i == n - 1];
}