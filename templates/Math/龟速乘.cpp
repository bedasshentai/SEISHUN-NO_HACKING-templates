ll mul(ll a, ll k, ll mod) {
    ll res = 0;
    while (k) {
        if (k & 1) res = (res + a) % mod;
        k >>= 1;
        a = (a + a) % mod;
    }
    return res;
}