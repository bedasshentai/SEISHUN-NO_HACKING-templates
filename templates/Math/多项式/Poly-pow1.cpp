void Poly_pow(int *f, int n, int k) {
    Poly_ln(f, n);
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * k % mod;
    Poly_exp(f, n);
}