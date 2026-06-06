#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int N = 2e6 + 10;
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