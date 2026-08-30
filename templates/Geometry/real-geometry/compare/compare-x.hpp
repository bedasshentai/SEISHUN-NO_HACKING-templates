// 依赖: point (type, 4.4.3), equals (function, 4.16.1)
template< typename R >
bool compare_x(const point<R> &a, const point<R> &b) {
  return not equals(a.x(), b.x()) ? a.x() < b.x() : a.y() < b.y();
}



