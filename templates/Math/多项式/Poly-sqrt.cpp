void Poly_sqrt(int *f, int m) {
    int n; for (n = 1; n < m; n <<= 1);
    static int b1[N << 1], b2[N << 1];
    b1[0] = 1;
    for (int len = 2; len <= n; len <<= 1) {
        for (int i = 0; i < len >> 1; i ++ ) b2[i] = (b1[i] << 1) % mod;
        Poly_inv(b2, len);
        NTT(b1, 1, len); px(b1, b1, len); NTT(b1, -1, len);
        for (int i = 0; i < len; i ++ ) b1[i] = (f[i] + b1[i]) % mod;
        covolution(b1, b2, len, len);
    }
    cpy(f, b1, m); clr(b1, n << 1); clr(b2, n << 1);
}