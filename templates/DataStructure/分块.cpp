int n, m, len; // len 为块长
ll add[M], sum[M];
ll w[N];

int get(int i) {
    return (i - 1) / len;
}

void change(int l, int r, int d) {
    if (get(l) == get(r)) {
        for (int i = l; i <= r; i ++ ) w[i] += d, sum[get(i)] += d;
    }
    else {
        int i = l, j = r;
        while (get(i) == get(l)) w[i] += d, sum[get(i)] += d, i ++ ;
        while (get(j) == get(r)) w[j] += d, sum[get(j)] += d, j -- ;
        for (int k = get(i); k <= get(j); k ++ ) sum[k] += len * d, add[k] += d;
    }
}

ll query(int l, int r) {
    ll res = 0;
    if (get(l) == get(r)) {
        for (int i = l; i <= r; i ++ ) res += w[i] + add[get(i)];
    }
    else {
        int i = l, j = r;
        while (get(i) == get(l)) res += w[i] + add[get(i)], i ++ ;
        while (get(j) == get(r)) res += w[j] + add[get(j)], j -- ;
        for (int k = get(i); k <= get(j); k ++ ) res += sum[k];
    }
    return res;
}