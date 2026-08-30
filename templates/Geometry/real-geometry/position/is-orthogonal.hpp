// 依赖: line (class, 4.4.2), inner_product (function, 4.13.3), equals (function, 4.16.1)
template< typename R >
bool is_orthogonal(const line<R> &l1, const line<R> &l2) {
  return equals<R>(inner_product<R>(l1.a - l1.b, l2.a - l2.b), 0);
}



