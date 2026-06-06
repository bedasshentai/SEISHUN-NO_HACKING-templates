#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
const int N = 1 << 17, mod = 998244353;

ll qpow(ll a, ll k = mod - 2) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return res;
}

void FWT_or(int *f, int op, int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                if (~op) (f[i | j | k] += f[i | j]) %= mod;
                else (f[i | j | k] += mod - f[i | j]) %= mod;
            }
        }
    }
}

void FWT_and(int *f, int op, int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                if (~op) (f[i | j] += f[i | j | k]) %= mod;
                else (f[i | j] += mod - f[i | j | k]) %= mod;
            }
        }
    }
}

void FWT_xor(int *f, int op, int n) {
    ll inv2 = (~op ? 1 : qpow(2));
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                int x = f[i | j], y = f[i | j | k];
                f[i | j] = (x + y) * inv2 % mod;
                f[i | j | k] = (mod + x - y) * inv2 % mod;
            }
        }
    }
}

void px(int *f, int *g, int n) {
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * g[i] % mod;
}

void print(int *f, int n) {
    for (int i = 0; i < n; i ++ ) cout << f[i] << " \n"[i == n - 1];
}

int n;
int A[N], B[N], a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n; n = 1 << n;
    for (int i = 0; i < n; i ++ ) cin >> A[i];
    for (int i = 0; i < n; i ++ ) cin >> B[i];
    
    cpy(a, A, n); cpy(b, B, n);
    FWT_or(a, 1, n); FWT_or(b, 1, n);
    px(a, b, n); FWT_or(a, -1, n);
    print(a, n);
    
    cpy(a, A, n); cpy(b, B, n);
    FWT_and(a, 1, n); FWT_and(b, 1, n);
    px(a, b, n); FWT_and(a, -1, n);
    print(a, n);
    
    cpy(a, A, n); cpy(b, B, n);
    FWT_xor(a, 1, n); FWT_xor(b, 1, n);
    px(a, b, n); FWT_xor(a, -1, n);
    print(a, n);
    return 0;
}