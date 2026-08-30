// 依赖: point (type, 4.4.3), line (class, 4.4.2), cross_point_ll (function, 4.8.4), perpendicular (function, 4.13.4)
template< typename R >
point<R> orthocenter(const point<R> &a, const point<R> &b, const point<R> &c) { // 垂心
  line<R> l1(a, a + perpendicular<R>(b - c));
  line<R> l2(b, b + perpendicular<R>(a - c));
  return cross_point_ll(l1, l2);
}



