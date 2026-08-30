// 依赖: segment (class, 4.4.5), point (type, 4.4.3), projection (function, 4.11.3), ccw (function, 4.13.1)
template< typename R >
R distance_sp(const segment<R> &s, const point<R> &p) {
  point<R> pr = projection({s.a, s.b}, p);
  if (ccw(s.a, s.b, pr) == 0) return std::abs(pr - p);
  return std::min(std::abs(s.a - p), std::abs(s.b - p));
}



