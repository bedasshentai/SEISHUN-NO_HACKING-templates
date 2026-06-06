void Poly_inv(int *f, int m) {
    int n; for (n = 1; n < m; n <<= 1);
    static int g1[N << 1], g2[N << 1], sav[N << 1];
    g1[0] = qpow(f[0]);
    for (int len = 2; len <= n; len <<= 1) {
        cpy(g2, g1, len >> 1), cpy(sav, f, len);
        NTT(g2, 1, len), NTT(sav, 1, len);
        px(g2, sav, len); NTT(g2, -1, len);
        clr(g2, len >> 1); cpy(sav, g1, len);
        NTT(sav, 1, len); NTT(g2, 1, len);
        px(g2, sav, len); NTT(g2, -1, len);
        for (int i = len >> 1; i < len; i ++ ) g1[i] = (2ll * g1[i] - g2[i] + mod) % mod;
    }
    cpy(f, g1, m), clr(g1, n), clr(g2, n), clr(sav, n);
}