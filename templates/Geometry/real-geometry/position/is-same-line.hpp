// 依赖: line (class, 4.4.2), cross_product (function, 4.13.2), sign (function, 4.16.8)
template< typename R >
bool is_same_line(const line<R> &l1, const line<R> &l2) { // 两直线是否相同
  return sign(cross_product<R>(l1.b - l1.a, l2.b - l2.a)) == 0 &&
         sign(cross_product<R>(l2.a - l1.a, l2.b - l1.a)) == 0;
}



