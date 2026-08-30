// 依赖: point (type, 4.4.3), line (class, 4.4.2), segment (class, 4.4.5), circle (class, 4.4.1), cross_point_cl (function, 4.8.2), point_on_segment (function, 4.15.11)
// 参数: s 为线段，o 为圆心，r 为半径
// 返回: tuple{type,p1,p2}：type 0 无 / 1 相切一点 / 2 一端点相交 / 3 两个交点
template< typename R >
std::tuple< int, point<R>, point<R> > cross_point_cs(const segment<R> &s, const point<R> &o, R r) {
  points<R> ps = cross_point_cl(circle<R>(o, r), line<R>(s.a, s.b));
  points<R> on;
  for (auto &p : ps) if (point_on_segment(p, s)) on.push_back(p);
  if (on.empty()) return {0, {}, {}};
  if (on.size() == 1) return {ps.size() == 1 ? 1 : 2, on[0], {}};
  return {3, on[0], on[1]};
}





