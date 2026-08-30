// 依赖: vec2d (class, 4.4.6)
template< typename R >
vec2d<R> rotate(const R theta, const vec2d<R> &v) {
  return {std::cos(theta) * v.x() + std::sin(-theta) * v.y(),
          std::sin(theta) * v.x() + std::cos(-theta) * v.y()};
}



