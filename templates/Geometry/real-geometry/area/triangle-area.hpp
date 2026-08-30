// 依赖: point (type, 4.4.3), cross_product (function, 4.13.2)
template< typename R >
R triangle_area(const point<R> &a, const point<R> &b, const point<R> &c) { // 三角形面积
  return std::abs(cross_product<R>(b - a, c - a)) / 2;
}



