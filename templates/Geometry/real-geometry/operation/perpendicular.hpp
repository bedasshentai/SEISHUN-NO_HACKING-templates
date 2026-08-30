// 依赖: vec2d (class, 4.4.6)
template< typename R >
vec2d<R> perpendicular(const vec2d<R> &v) { // 逆时针旋转 90°
  return vec2d<R>(-v.y(), v.x());
}



