#include<bits/stdc++.h>
using namespace std;

#define NTT_mod

#ifdef NTT_mod

#define ll long long
#define i128 __int128
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + (n))
const int _G = 3, _i = 86583718, mod = 998244353;
const int N = 2e5 + 10;

ll qpow(ll a, ll k = mod - 2) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return res;
}

const int invG = qpow(_G), invi = qpow(_i), inv2 = qpow(2);
int rev[N << 1], rev_len;

void rev_init(int n) {
    if (rev_len == n) return;
    for (int i = 0; i < n; i ++ ) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
    rev_len = n;
}

void NTT(int *g, int op, int n) {
    rev_init(n);
    static ull f[N << 1], Gk[N << 1] = {1};
    for (int i = 0; i < n; i ++ ) f[i] = g[rev[i]];
    for (int k = 1; k < n; k <<= 1) {
        int G1 = qpow(~op ? _G : invG, (mod - 1) / (k << 1));
        for (int i = 1; i < k; i ++ ) Gk[i] = Gk[i - 1] * G1 % mod;
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                int tmp = Gk[j] * f[i | j | k] % mod;
                f[i | j | k] = f[i | j] + mod - tmp;
                f[i | j] += tmp;
            }
        }
        if (k == (1 << 10)) for (int i = 0; i < n; i ++ ) f[i] %= mod;
    }
    if (~op) for (int i = 0; i < n; i ++ ) g[i] = f[i] % mod;
    else {
        int invn = qpow(n);
        for (int i = 0; i < n; i ++ ) g[i] = f[i] % mod * invn % mod;
    }
}

void px(int *f, int *g, int n) {
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * g[i] % mod;
}

int inv[N << 1], inv_len;

void inv_init(int n) {
    if (n <= inv_len) return;
    if (!inv_len) inv[0] = inv[1] = 1, inv_len = 1;
    for (int i = inv_len + 1; i <= n; i ++ ) inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
    inv_len = n;
}

void Poly_d(int *f, int n) {
    for (int i = 1; i < n; i ++ ) f[i - 1] = 1ll * f[i] * i % mod;
    f[n - 1] = 0;
}

void Poly_int(int *f, int n) {
    for (int i = n; i; i -- ) f[i] = 1ll * f[i - 1] * inv[i] % mod;
    f[0] = 0;
}

void covolution(int *f, int *g, int len, int lim) {
    static int sav[N << 1];
    int n; for (n = 1; n < len << 1; n <<= 1);
    clr(sav, n); cpy(sav, g, n);
    NTT(sav, 1, n); NTT(f, 1, n);
    px(f, sav, n); NTT(f, -1, n);
    clr(f + lim, n - lim), clr(sav, n);
}

void Poly_inv(int *f, int m) {
    static int b1[N << 1], b2[N << 1], sav[N << 1];
    int n; for (n = 1; n < m; n <<= 1);
    b1[0] = qpow(f[0]);
    for (int len = 2; len <= n; len <<= 1) {
        cpy(b2, b1, len >> 1), cpy(sav, f, len);
        NTT(b2, 1, len), NTT(sav, 1, len);
        px(b2, sav, len); NTT(b2, -1, len);
        clr(b2, len >> 1); cpy(sav, b1, len);
        NTT(sav, 1, len); NTT(b2, 1, len);
        px(b2, sav, len); NTT(b2, -1, len);
        for (int i = len >> 1; i < len; i ++ ) b1[i] = (2ll * b1[i] - b2[i] + mod) % mod;
    }
    cpy(f, b1, m), clr(b1, n), clr(b2, n), clr(sav, n);
}

void Poly_sqrt(int *f, int m) {
    static int b1[N << 1], b2[N << 1];
    int n; for (n = 1; n < m; n <<= 1);
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

void Poly_div(int *f, int *g, int n, int m) {
    static int b1[N << 1], b2[N << 1];
    int len = n - m + 1;
    rev(f, n); cpy(b2, f, len); rev(f, n);
    rev(g, m); cpy(b1, g, len); rev(g, m);
    Poly_inv(b1, len); covolution(b1, b2, len, len); rev(b1, len);
    covolution(g, b1, n, n);
    for (int i = 0; i < m - 1; i ++ ) g[i] = (f[i] - g[i] + mod) % mod;
    clr(g + m - 1, len); cpy(f, b1, len); clr(f + len, n - len);
}

void Poly_ln(int *f, int n) {
    static int sav[N << 1];
    inv_init(n); cpy(sav, f, n);
    Poly_d(sav, n); Poly_inv(f, n);
    covolution(f, sav, n, n); Poly_int(f, n - 1);
    clr(sav, n);
}

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

void Poly_qpow(int *f, int n, ll k) {
    static int sav[N << 1];
    int len1 = n, len2 = 1;
    sav[0] = 1;
    while (k) {
        if (k & 1) {
            covolution(f, sav, len1 + len2 >> 1, len1 + len2 - 1);
            len1 = len1 + len2 - 1;
        }
        covolution(sav, sav, len2, (len2 << 1) - 1);
        len2 = (len2 << 1) - 1;
        k >>= 1;
    }
    clr(sav, len2);
}

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

void Poly_print(int *f, int n) {
    for (int i = 0; i < n; i ++ ) cout << f[i] << " \n"[i == n - 1];
}

int n; string k;
int f[N << 1], g[N << 1];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> f[i];
    cpy(g, f, n); Poly_inv(g, n); Poly_print(g, n);
    cpy(g, f, n); Poly_sqrt(g, n); Poly_print(g, n);
    cpy(g, f, n); Poly_ln(g, n); Poly_print(g, n);
    cpy(g, f, n); Poly_exp(g, n); Poly_print(g, n);
    cpy(g, f, n); Poly_pow(g, n, k); Poly_print(g, n);
}

/*
6 179176919845134813855136
1 9 583 8235 1934 13153
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T -- ) solve();
    return 0;
}

#endif

#ifdef FFT_mod

#define ll long long
#define ld long double
#define clr(f, n) memset(f, 0, sizeof(Complex) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(Complex) * (n))
#define rev(f, n) reverse(f, f + (n))
const int N = 1.5e6 + 10;
const ld Pi = acos(-1);

struct Complex {
    ld x, y;
    Complex (ld xx = 0, ld yy = 0) {x = xx, y = yy;}
    Complex operator+ (Complex const &C) const {return Complex(x + C.x, y + C.y);}
    Complex operator+ (ld R) {return Complex(x + R, y);}
    Complex operator- (Complex const &C) const {return Complex(x - C.x, y - C.y);}
    Complex operator- (ld R) {return Complex(x - R, y);}
    Complex operator* (Complex const &C) const {return Complex(x * C.x - y * C.y, x * C.y + y * C.x);}
    Complex operator/ (const ld &R) const {return Complex(x / R, y / R);}
    Complex operator~ () {return Complex(x, -y);}
};

int rev[N << 1], rev_len;

void rev_init(int n) {
    if (rev_len == n) return;
    for (int i = 0; i < n; i ++ ) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
    rev_len = n;
}

void FFT(Complex *f, int op, int n) {
    rev_init(n);
    for (int i = 0; i < n; i ++ ) if (i < rev[i]) swap(f[i], f[rev[i]]);
    for (int k = 1; k < n; k <<= 1) {
        Complex w1 = Complex(cos(Pi / k), op * sin(Pi / k));
        for (int i = 0; i < n; i += k << 1) {
            Complex wk = Complex(1, 0);
            for (int j = 0; j < k; j ++ , wk = wk * w1) {
                Complex x = f[i + j], y = wk * f[i + j + k];
                f[i + j] = x + y, f[i + j + k] = x - y;
            }
        }
    }
    if (op == -1) for (int i = 0; i < n; i ++ ) f[i] = f[i] / n;
}

void px(Complex *f, Complex *g, int n) {
    for (int i = 0; i < n; i ++ ) f[i] = f[i] * g[i];
}

void covolution(Complex *f, Complex *g, int len, int lim) {
    static Complex sav[N << 1];
    int n; for (n = 1; n < len << 1; n <<= 1);
    clr(sav, n); cpy(sav, g, n);
    FFT(sav, 1, n); FFT(f, 1, n);
    px(f, sav, n); FFT(f, -1, n);
    clr(f + lim, n - lim), clr(sav, n);
}

void CDQ(Complex *f, Complex *g, int l, int r) {
    static Complex b1[N << 1], b2[N << 1];
    if (l == r) {
        if (!l) f[l] = 1;
        return;
    }
    int mid = l + r >> 1;
    CDQ(f, g, l, mid);
    int n; for (n = 1; n <= r - l + 1; n <<= 1);
    cpy(b1, f + l, mid - l + 1); clr(b1 + mid - l + 1, n - (mid - l));
    cpy(b2, g, r - l + 1); clr(b2 + r - l + 1, n - (r - l));
    FFT(b1, 1, n); FFT(b2, 1, n); px(b1, b2, n); FFT(b1, -1, n);
    for (int i = mid + 1; i <= r; i ++ ) f[i] = f[i] + b1[i - l];
    clr(b1, n); clr(b2, n);
    CDQ(f, g, mid + 1, r);
}

void Poly_print(Complex *f, int op, int n) {
    for (int i = 0; i < n; i ++ ) cout << (ll)((op ? f[i].y : f[i].x) + 0.5) << " \n"[i == n - 1];
}

int n;
Complex F[N << 1];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> F[i].x, F[i].y = F[i].x;
    covolution(F, F, n, n << 1);
    for (int i = 0; i < n << 1; i ++ ) F[i] = F[i] / 2;
    Poly_print(F, 1, (n << 1) - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T -- ) solve();
    return 0;
}

#endif