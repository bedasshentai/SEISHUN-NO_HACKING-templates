// 依赖: point (type, 4.4.3), line (class, 4.4.2), cross_product (function, 4.13.2), sign (function, 4.16.8)
template< typename R >
bool is_on_line(const point<R> &a, const point<R> &b, const point<R> &c) { // 三点共线
  return sign(cross_product<R>(b - a, c - a)) == 0;
}

template< typename R >
bool is_on_line(const point<R> &p, const line<R> &l) { // 点是否在直线上
  return is_on_line(p, l.a, l.b);
}



