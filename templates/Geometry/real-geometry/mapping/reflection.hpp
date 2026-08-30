// 依赖: line (class, 4.4.2), point (type, 4.4.3), projection (function, 4.11.3)
template< typename R >
point<R> reflection(const line<R> &l, const point<R> &p) {
  return 2 * projection(l, p) - p;
}



