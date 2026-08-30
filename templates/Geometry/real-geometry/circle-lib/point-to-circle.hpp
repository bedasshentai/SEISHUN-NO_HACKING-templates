// 依赖: point (type, 4.4.3), normalize (function, 4.11.1), sign (function, 4.16.8)
template< typename R >
point<R> closest_point_on_circle(const point<R> &p, const point<R> &o, R r) { // 点到圆的最近点
  point<R> v = p - o;
  if (sign(std::abs(v)) == 0) return o; // 圆心
  return o + normalize(v) * r;
}



