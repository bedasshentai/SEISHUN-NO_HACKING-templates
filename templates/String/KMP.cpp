// S 为模式串, P 为匹配串, 1-index

for (int i = 2, j = 0; i <= n; i ++ ) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

for (int i = 1, j = 0; i <= m; i ++ ) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == n) {
        /*匹配成功*/
        j = ne[j];
    }
}