// 依赖: point (type, 4.4.3), cross_product (function, 4.13.2), inner_product (function, 4.13.3)
template< typename R >
R vector_angle(const point<R> &a, const point<R> &b) { // 求两向量夹角（弧度）
  return std::abs(std::atan2(cross_product(a, b), inner_product(a, b)));
}



