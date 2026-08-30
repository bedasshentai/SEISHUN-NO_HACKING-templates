// 依赖: point (type, 4.4.3)
template< typename R >
R distance_pp(const point<R> &a, const point<R> &b) { // 欧几里得距离
  return std::abs(a - b);
}



