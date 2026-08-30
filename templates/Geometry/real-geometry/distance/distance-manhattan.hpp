// 依赖: point (type, 4.4.3)
template< typename R >
R manhattan_distance(const point<R> &a, const point<R> &b) { // 曼哈顿距离
  return std::abs(a.x() - b.x()) + std::abs(a.y() - b.y());
}



