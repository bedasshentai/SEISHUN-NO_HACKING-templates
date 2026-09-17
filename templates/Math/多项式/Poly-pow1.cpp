void Poly_pow(int *f, int n, int k) { // A[0] = 1
    Poly_ln(f, n);
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * k % mod;
    Poly_exp(f, n);
}