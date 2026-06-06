void CDQ(int *f, int *g, int l, int r) {
    static int b1[N << 1], b2[N << 1];
    if (l == r) {
        if (!l) f[l] = 1;
        return;
    }
    int mid = l + r >> 1;
    CDQ(f, g, l, mid);
    int n; for (n = 1; n <= r - l + 1; n <<= 1);
    cpy(b1, f + l, mid - l + 1); clr(b1 + mid - l + 1, n - (mid - l));
    cpy(b2, g, r - l + 1); clr(b2 + r - l + 1, n - (r - l));
    NTT(b1, 1, n); NTT(b2, 1, n); px(b1, b2, n); NTT(b1, -1, n);
    for (int i = mid + 1; i <= r; i ++ ) f[i] = (f[i] + b1[i - l]) % mod;
    clr(b1, n); clr(b2, n);
    CDQ(f, g, mid + 1, r);
}