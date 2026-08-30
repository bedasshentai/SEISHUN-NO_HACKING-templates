// 依赖: point (type, 4.4.3), line (class, 4.4.2), polygon (type, 4.4.4), cross_point_ll (function, 4.8.4), cross_product (function, 4.13.2), inner_product (function, 4.13.3), point_on_line_left (function, 4.15.9), equals (function, 4.16.1), sign (function, 4.16.8)
// 参数: lines 为有向直线(左侧半平面)
// 返回: 交集凸多边形，空/无界时为空
// 每条有向直线表示其左侧半平面；返回交集（凸多边形），无界/为空时返回空
template< typename R >
polygon<R> halfplane_intersection(std::vector< line<R> > lines) {
  auto angle = [](const point<R> &v) { return std::atan2(v.y(), v.x()); };

  std::sort(lines.begin(), lines.end(), [&](const line<R> &a, const line<R> &b) {
    point<R> da = a.b - a.a, db = b.b - b.a;
    R aa = angle(da), ab = angle(db);
    if (!equals(aa, ab)) return aa < ab;
    return cross_product<R>(db, a.a - b.a) < 0;
  });

  std::vector< line<R> > uniq;
  for (auto &l : lines) {
    if (!uniq.empty() && equals(angle(l.b - l.a), angle(uniq.back().b - uniq.back().a))) continue;
    uniq.push_back(l);
  }

  std::deque< line<R> > ls;
  std::deque< point<R> > ps;
  for (auto &l : uniq) {
    while (ps.size() && !point_on_line_left(ps.back(), l)) { ps.pop_back(); ls.pop_back(); }
    while (ps.size() && !point_on_line_left(ps.front(), l)) { ps.pop_front(); ls.pop_front(); }
    if (ls.empty()) { ls.push_back(l); continue; }
    if (sign(cross_product<R>(l.b - l.a, ls.back().b - ls.back().a)) == 0) {
      if (inner_product<R>(l.b - l.a, ls.back().b - ls.back().a) < 0) return {};
      continue;
    }
    ps.push_back(cross_point_ll(ls.back(), l));
    ls.push_back(l);
  }

  while (ps.size() && !point_on_line_left(ps.back(), ls.front())) { ps.pop_back(); ls.pop_back(); }
  if (ls.size() <= 2) return {};
  ps.push_back(cross_point_ll(ls.back(), ls.front()));
  return polygon<R>(ps.begin(), ps.end());
}




