// 依赖: vec2d (class, 4.4.6), equals (function, 4.16.1)
template< typename R >
bool equals(const vec2d<R> &a, const vec2d<R> &b) {
  return equals(a.x(), b.x()) and equals(a.y(), b.y());
}



