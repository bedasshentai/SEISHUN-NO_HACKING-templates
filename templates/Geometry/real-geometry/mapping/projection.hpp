// 依赖: line (class, 4.4.2), point (type, 4.4.3), inner_product (function, 4.13.3)
template< typename R >
point<R> projection(const line<R> &l, const point<R> &p) {
  R t = inner_product<R>(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}



