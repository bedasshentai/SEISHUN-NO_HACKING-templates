void Poly_exp(int *f, int m) {
    static int b1[N << 1], b2[N << 1];
    int n; for (n = 1; n < m; n <<= 1);
    b1[0] = 1;
    for (int len = 2; len <= n; len <<= 1) {
        cpy(b2, b1, len >> 1); Poly_ln(b2, len);
        for (int i = 0; i < len; i ++ ) b2[i] = (f[i] - b2[i] + mod) % mod;
        b2[0] = (b2[0] + 1) % mod;
        covolution(b1, b2, len, len);
    }
    cpy(f, b1, m); clr(b1, n); clr(b2, n);
}