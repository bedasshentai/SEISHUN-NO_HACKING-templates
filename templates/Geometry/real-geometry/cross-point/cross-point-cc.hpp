// 依赖: circle (class, 4.4.1), point (type, 4.4.3), points (type, 4.4.3), equals (function, 4.16.2), sign (function, 4.16.8)
// 参数: a、b 为两个圆
// 返回: 0~2 个交点组成的点集
template< typename R >
points<R> cross_point_cc(const circle<R> &a, const circle<R> &b) {
  R d = std::abs(a.o - b.o), r = a.r + b.r;

  if (sign(d - r) > 0 or sign(d + a.r - b.r) < 0) return {};

  R s = std::acos( (std::norm(a.r) - std::norm(b.r) + std::norm(d)) / (2 * a.r * d) );
  R t = std::arg(b.o - a.o);

  point<R> p{a.o + std::polar(a.r, t + s)};
  point<R> q{a.o + std::polar(a.r, t - s)};

  if (equals(p, q)) return {p};
  return {p, q};
}





