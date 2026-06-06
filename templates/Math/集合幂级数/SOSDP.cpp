for (int i = 0; i < n; i ++ )          // 枚举每一位
    for (int j = 0; j < 1 << n; j ++ )
        if (j >> i & 1)
            f[j] += f[j ^ (1 << i)];