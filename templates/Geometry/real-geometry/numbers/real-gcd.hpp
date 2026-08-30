// 依赖: eps (function, 4.5.1)
template< typename R >
R real_gcd(R x, R y) { // 实数域 gcd
  return std::abs(y) < eps() ? std::abs(x) : real_gcd(y, std::fmod(x, y));
}



