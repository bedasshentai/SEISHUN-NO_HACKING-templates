void Poly_ln(int *f, int n) {
    static int sav[N << 1];
    inv_init(n); cpy(sav, f, n);
    Poly_d(sav, n); Poly_inv(f, n);
    covolution(f, sav, n, n); Poly_int(f, n - 1);
    clr(sav, n);
}