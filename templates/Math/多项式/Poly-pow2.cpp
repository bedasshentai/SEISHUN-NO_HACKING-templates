void Poly_pow(int *f, int n, string k) {
    int k1 = 0, k2 = 0, p = 0, c;
    while (!f[p]) p ++ ;
    for (int i = 0; k[i]; i ++ ) {
        k1 = (10ll * k1 + k[i] - '0') % mod;
        k2 = (10ll * k2 + k[i] - '0') % (mod - 1);
        if (1ll * k1 * p >= n) return clr(f, n), void();
    }
    n -= p * k1; c = qpow(f[p]);
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i + p] * c % mod;
    clr(f + n, p * k1); Poly_ln(f, n); 
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * k1 % mod;
    Poly_exp(f, n); c = qpow(c, mod - 1 - k2);
    for (int i = n - 1; i >= 0; i -- ) f[p * k1 + i] = 1ll * f[i] * c % mod;
    clr(f, p * k1);
}