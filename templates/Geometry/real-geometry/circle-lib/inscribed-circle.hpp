// 依赖: circle (class, 4.4.1), point (type, 4.4.3), distance_sp (function, 4.9.5)
template< typename R >
circle<R> inscribed_circle(const point<R> &a, const point<R> &b, const point<R> &c) {
  R A = std::abs(b - c), B = std::abs(c - a), C = std::abs(a - b);

  point<R> o((a * A + b * B + c * C) / (A + B + C));
  R r = distance_sp({a, b}, o);

  return {o, r};
}



