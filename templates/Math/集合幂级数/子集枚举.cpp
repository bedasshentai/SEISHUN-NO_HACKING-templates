for (int S = 0; S < 1 << n; S ++ )
    for (int T = S; T; T = (T - 1) & S)