// 如果乘法会溢出需要使用快速乘
vector<int> base = {2, 7, 61};

bool check(ll a, ll p) {
    ll d = p - 1, r = 0;
    while (!(d & 1)) r ++ , d >>= 1;
    ll now = qpow(a, d, p);
    if (now == 1) return 1;
    while (r -- ) {
        if (now == p - 1) return 1;
        now = now * now % p;
    }
    return 0;
}

// 筛过素数的直接查，否则 klog 复杂度判定
bool Miller_Rabin(int x) {
    if (x < n) return !st[x];
    for (auto a : base) if (!check(a, x)) return 0;
    return 1;
}