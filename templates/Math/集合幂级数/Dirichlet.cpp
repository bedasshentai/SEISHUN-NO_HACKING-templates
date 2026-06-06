// Dirichlet 前缀和
for (int i = 0; i < cnt; i ++ ) {           // 枚举每个质数
    for (int j = 1; j * primes[i] <= N; j ++ ) {
        f[j * primes[i]] += f[j];
    }
}

// Dirichlet 后缀和
for (int i = 0; i < cnt; i ++ ) {
    for (int j = N / primes[i]; j >= 1; j -- ) {    // 注意倒序防止重复
        f[j] += f[j * primes[i]];
    }
}

// Dirichlet 前缀差
for (int i = 0; i < cnt; i ++ ) {
    for (int j = N / primes[i]; j >= 1; j -- ) {
        f[j * primes[i]] -= f[j];
    }
}

// Dirichlet 后缀差
for (int i = 0; i < cnt; i ++ ) {
    for (int j = 1; j * primes[i] <= N; j ++ ) {
        f[j] -= f[j * primes[i]];
    }
}