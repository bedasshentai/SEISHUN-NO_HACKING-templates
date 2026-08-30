// 依赖: point (type, 4.4.3), line (class, 4.4.2), segment (class, 4.4.5), projection (function, 4.11.3), ccw (function, 4.13.1)
// 参数: s 为线段，p 为点
// 返回: 点到线段的最近点；point_to_segment 额外返回距离
template< typename R >
point<R> closest_point_sp(const segment<R> &s, const point<R> &p) { // 点到线段的最近点
  point<R> pr = projection(line<R>(s.a, s.b), p);
  if (ccw(s.a, s.b, pr) == 0) return pr;
  return std::abs(s.a - p) < std::abs(s.b - p) ? s.a : s.b;
}

template< typename R >
std::pair< point<R>, R > point_to_segment(const segment<R> &s, const point<R> &p) {
  point<R> q = closest_point_sp(s, p);
  return {q, std::abs(p - q)};
}





