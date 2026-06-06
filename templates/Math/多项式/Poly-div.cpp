void Poly_div(int *f, int *g, int n, int m) {
    static int Q[N << 1], R[N << 1];
    int len = n - m + 1;
    rev(f, n); cpy(R, f, len); rev(f, n);
    rev(g, m); cpy(Q, g, len); rev(g, m);
    Poly_inv(Q, len); covolution(Q, R, len, len); rev(Q, len);
    covolution(g, Q, n, n);
    for (int i = 0; i < m - 1; i ++ ) g[i] = (f[i] - g[i] + mod) % mod;
    clr(g + m - 1, len); cpy(f, Q, len); clr(f + len, n - len);
}