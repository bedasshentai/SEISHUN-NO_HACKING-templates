// 依赖: vec2d (class, 4.4.6)
template< typename R >
R cross_product(const vec2d<R> &a, const vec2d<R> &b) {
  return a.x() * b.y() - a.y() * b.x();
}



