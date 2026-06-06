void Poly_sin(int *f, int n) {
    static int sav[N << 1];
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * _i % mod;
    for (int i = 0; i < n; i ++ ) sav[i] = (mod - f[i]) % mod;
    Poly_exp(f, n); Poly_exp(sav, n);
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * (f[i] - sav[i] + mod) * invi % mod * inv2 % mod;
    clr(sav, n);
}

void Poly_cos(int *f, int n) {
    static int sav[N << 1];
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * _i % mod;
    for (int i = 0; i < n; i ++ ) sav[i] = (mod - f[i]) % mod;
    Poly_exp(f, n); Poly_exp(sav, n);
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * (f[i] + sav[i]) * inv2 % mod;
    clr(sav, n);
}