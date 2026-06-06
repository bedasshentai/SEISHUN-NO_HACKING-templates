#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N = 2e5 + 10;
const ld PI = acos(-1);

struct Complex {
    ld x, y;
    Complex(ld xx = 0, ld yy = 0) {x = xx, y = yy;}
    Complex operator+ (const Complex &C) const {return Complex(x + C.x, y + C.y);}
    Complex operator- (const Complex &C) const {return Complex(x - C.x, y - C.y);}
    Complex operator* (const Complex &C) const {return Complex(C.x * x - C.y * y, C.y * x + C.x * y);}
    Complex operator* (const ld n) const {return Complex(x * n, y * n);}
    Complex operator/ (const ld n) const {return Complex(x / n, y / n);}
    Complex operator~ () const {return Complex(x, -y);}
}F[N << 1], G[N << 1], T[N << 1];

int rev_len, rev[N << 1];

void rev_init(int n) {
    if (n == rev_len) return;
    for (int i = 0; i < n; i ++ ) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
    rev_len = n;
}

void FFT(Complex *f, int op, int n) {
    rev_init(n);
    static Complex wk[N << 1] = {Complex(1, 0)};
    for (int i = 0; i < n; i ++ ) if (i < rev[i]) swap(f[i], f[rev[i]]);
    for (int k = 1; k < n; k <<= 1) {
        Complex w1 = Complex(cos(PI / k), op * sin(PI / k));
        for (int i = 1; i < k; i ++ ) wk[i] = wk[i - 1] * w1;
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                Complex x = f[i | j], y = wk[j] * f[i | j | k];
                f[i | j] = x + y, f[i | j | k] = x - y;
            }
        }
    }
    if (op == -1) for (int i = 0; i < n; i ++ ) f[i] = f[i] / n;
}

int n, m, mod;
int a[N << 1];

void solve() {
    cin >> n >> m >> mod;
    for (int i = 0; i <= n; i ++ ) cin >> a[i], F[i].x = a[i] & ((1 << 15) - 1), G[i].x = a[i] >> 15;
    for (int i = 0; i <= m; i ++ ) cin >> a[i], T[i].x = a[i] & ((1 << 15) - 1), T[i].y = a[i] >> 15;
    int len; for (len = 1; len <= n + m; len <<= 1);
    FFT(F, 1, len); FFT(G, 1, len); FFT(T, 1, len);
    for (int i = 0; i < len; i ++ ) F[i] = F[i] * T[i], G[i] = G[i] * T[i];
    FFT(F, -1, len); FFT(G, -1, len);
    for (int i = 0; i <= n + m; i ++ ) a[i] = ((ll)round(F[i].x) % mod + (((ll)(round(F[i].y) + round(G[i].x)) % mod) << 15) % mod + (((ll)round(G[i].y) % mod) << 30) % mod) % mod;
    for (int i = 0; i <= n + m; i ++ ) cout << (a[i] % mod + mod) % mod << " ";
}