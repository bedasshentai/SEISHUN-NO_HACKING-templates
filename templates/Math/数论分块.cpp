for (int l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
	// 块的和 * 块的权
    Sum += (g[r] - g[l - 1]) * (n / l);
}