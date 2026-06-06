#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + (n))

const int N = 1050000, _G = 3, mod = 998244353;

ll ksm(ll a, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return res;
}

const int invG = ksm(_G, mod - 2);
int rev[N << 1], rev_len;

void rev_init(int n) {
    if (n == rev_len) return;
    for (int i = 0; i < n; i ++ ) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
    rev_len = n;
}

void NTT(int *g, int op, int n) {
    rev_init(n);
    static ull f[N << 1], Gk[N << 1] = {1};
    for (int i = 0; i < n; i ++ ) f[i] = g[rev[i]];
    for (int k = 1; k < n; k <<= 1) {
        int G1 = ksm(~op ? _G : invG, (mod - 1) / (k << 1));          // 所在群的阶
        for (int i = 1; i < k; i ++ ) Gk[i] = Gk[i - 1] * G1 % mod;        // 预处理单位根
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j ++ ) {
                int tmp = Gk[j] * f[i | j | k] % mod;                // 位运算加速
                f[i | j | k] = f[i | j] + mod - tmp;
                f[i | j] += tmp;
            }
        }
        if (k == (1 << 10)) for (int i = 0; i < n; i ++ ) f[i] %= mod;      // 由于总是加法，在中间取一次模即可
    }
    if (~op) for (int i = 0; i < n; i ++ ) g[i] = f[i] % mod;
    else {
        int invn = ksm(n, mod - 2);
        for (int i = 0; i < n; i ++ ) g[i] = f[i] % mod * invn % mod;
    }
}

void px (int *f, int *g, int n) {
    for (int i = 0; i < n; i ++ ) f[i] = 1ll * f[i] * g[i] % mod;
}

void covolution(int *f, int *g, int len, int lim) {
    static int sav[N << 1];
    int n; for (n = 1; n < len << 1; n <<= 1);
    clr(sav, n); cpy(sav, g, n);
    NTT(sav, 1, n); NTT(f, 1, n);
    px(f, sav, n); NTT(f, -1, n);
    clr(f + lim, n - lim), clr(sav, n);
}