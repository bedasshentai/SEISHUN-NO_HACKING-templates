// 依赖: circle (class, 4.4.1), point (type, 4.4.3), cross_product (function, 4.13.2)
template< typename R >
circle<R> circumscribed_circle(const point<R> &a, const point<R> &b, const point<R> &c) {
  R A = std::norm(b - c), B = std::norm(c - a), C = std::norm(a - b);

  R S = std::norm(cross_product<R>(b - a, c - a));
  R T = A + B + C;

  point<R> o{(A*(T - 2*A) * a + B*(T - 2*B) * b + C*(T - 2*C) * c) / (4 * S)};

  return circle(o, std::abs(o - a));
}



