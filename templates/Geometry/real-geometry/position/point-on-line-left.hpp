// 依赖: point (type, 4.4.3), line (class, 4.4.2), cross_product (function, 4.13.2)
template< typename R >
bool point_on_line_left(const point<R> &p, const line<R> &l) { // 点是否在直线左侧
  return cross_product<R>(l.b - l.a, p - l.a) > 0;
}



