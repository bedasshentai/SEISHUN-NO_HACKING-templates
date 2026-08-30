// 依赖: line (class, 4.4.2), point (type, 4.4.3), projection (function, 4.11.3)
template< typename R >
R distance_lp(const line<R> &l, const point<R> &p) {
  point<R> pr = projection(l, p);
  return std::abs(pr - p);
}



