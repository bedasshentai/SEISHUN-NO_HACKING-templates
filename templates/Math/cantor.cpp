// 康托展开：p 为 0..n-1 的排列，返回排名（从 0 开始）
ll cantor(const vector<int>& p) {
    int n = (int)p.size();
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
            if (p[j] < p[i]) cnt++;
        res += (ll)cnt * fact[n - 1 - i];
    }
    return res;
}

// 逆康托展开：rank 从 0 开始，返回 0..n-1 的排列
vector<int> decantor(ll rank, int n) {
    vector<int> avail(n);
    iota(avail.begin(), avail.end(), 0);   // 可用数字 0..n-1
    vector<int> p;
    p.reserve(n);
    for (int i = n; i >= 1; i--) {
        ll f = fact[i - 1];
        int idx = (int)(rank / f);         // 第 idx 小的可用数字（0-indexed）
        rank %= f;
        p.push_back(avail[idx]);
        avail.erase(avail.begin() + idx);
    }
    return p;
}