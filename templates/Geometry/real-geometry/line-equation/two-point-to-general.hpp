// 依赖: point (type, 4.4.3), line (class, 4.4.2), real_gcd (function, 4.12.4)
// 参数: l 为直线
// 返回: (A,B,C) 满足 Ax+By=C
template< typename R >
std::tuple< R, R, R > two_point_to_general(const line<R> &l) { // 两点式转一般式 Ax + By = C
  R A = l.a.y() - l.b.y(), B = l.b.x() - l.a.x(), C = l.a.x() * A + l.a.y() * B;
  if (A < 0) {
    A = -A, B = -B, C = -C;
  } else if (A == 0) {
    if (B < 0) { B = -B, C = -C; }
    else if (B == 0 && C < 0) { C = -C; }
  }
  if (A == 0) {
    if (B == 0) { C = 0; }
    else { R g = real_gcd(std::abs(B), std::abs(C)); B /= g, C /= g; }
  } else if (B == 0) {
    R g = real_gcd(std::abs(A), std::abs(C)); A /= g, C /= g;
  } else {
    R g = real_gcd(real_gcd(std::abs(A), std::abs(B)), std::abs(C));
    A /= g, B /= g, C /= g;
  }
  return {A, B, C};
}




