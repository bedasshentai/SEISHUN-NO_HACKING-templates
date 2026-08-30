// 依赖: point (type, 4.4.3), equals (function, 4.16.1)
template< typename R >
bool compare_y(const point<R> &a, const point<R> &b) {
  return not equals(a.y(), b.y()) ? a.y() < b.y() : a.x() < b.x();
}



