void init() {
    int k = 0;
    b[k ++ ] = '$';
    b[k ++ ] = '#';
    for (int i = 0; i < n; i ++ ) {
        b[k ++ ] = a[i];
        b[k ++ ] = '#';
    }
    b[n = k] = '^';
}

void manacher() {
    int mx = 1, mid = 1;
    for (int i = 1; i <= n; i ++ ) {
        if (i < mx)  p[i] = min(p[mid * 2 - i], mx - i);
        else p[i] = 1;
        while (b[i + p[i]] == b[i - p[i]]) p[i] ++ ;
        if (i + p[i] > mx) {
            mx = i + p[i];
            mid = i;
        }
    }
}