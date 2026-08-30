// parallel

// 依赖: line (class, 4.4.2), cross_product (function, 4.13.2), equals (function, 4.16.1)
template< typename R >
bool is_parallel(const line<R> &l1, const line<R> &l2) {
  return equals<R>(cross_product<R>(l1.b - l1.a, l2.b - l2.a), 0);
}



