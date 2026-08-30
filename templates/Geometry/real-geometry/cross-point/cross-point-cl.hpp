// 依赖: circle (class, 4.4.1), point (type, 4.4.3), points (type, 4.4.3), line (class, 4.4.2), projection (function, 4.11.3), sign (function, 4.16.8)
// 参数: c 为圆，l 为直线
// 返回: 0~2 个交点组成的点集
template< typename R >
points<R> cross_point_cl(const circle<R> &c, const line<R> &l) {
  point<R> pr = projection(l, c.center());

  R d = std::norm(c.radius()) - std::norm(pr - c.center());

  if (sign(d) == -1) {
    return {};
  }
  if (sign(d) == 0) {
    return {pr};
  }

  point<R> e = (l.b - l.a) / std::abs(l.b - l.a);
  R k = std::sqrt(d);
  return {pr + e * k, pr - e * k};
}





