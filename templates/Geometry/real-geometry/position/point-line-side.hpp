// 依赖: point (type, 4.4.3), line (class, 4.4.2), cross_product (function, 4.13.2), sign (function, 4.16.8)
template< typename R >
bool same_side(const point<R> &p1, const point<R> &p2, const line<R> &l) { // 同侧
  return sign(cross_product<R>(p1 - l.a, l.b - l.a) * cross_product<R>(p2 - l.a, l.b - l.a)) == 1;
}

template< typename R >
bool opposite_side(const point<R> &p1, const point<R> &p2, const line<R> &l) { // 异侧
  return sign(cross_product<R>(p1 - l.a, l.b - l.a) * cross_product<R>(p2 - l.a, l.b - l.a)) == -1;
}



