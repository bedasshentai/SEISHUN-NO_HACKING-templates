// 依赖: line (class, 4.4.2), point (type, 4.4.3), cross_product (function, 4.13.2), equals (function, 4.16.1)
template< typename R >
point<R> cross_point_ll(const line<R> &l1, const line<R> &l2) {
  R a = cross_product<R>(l1.b - l1.a, l2.b - l2.a);
  R b = cross_product<R>(l1.b - l1.a, l1.b - l2.a);
  if (equals<R>(a, 0) && equals<R>(b, 0)) return l2.a;
  return l2.a + (l2.b - l2.a) * b / a;
}



