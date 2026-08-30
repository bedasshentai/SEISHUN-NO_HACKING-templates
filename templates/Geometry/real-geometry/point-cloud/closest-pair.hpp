// 依赖: point (type, 4.4.3)
template< typename R >
using closest_pair_result_t = std::pair< R, std::pair<point<R>, point<R> > >;

// WARNING: pts are sorted by y after calling this function
// 依赖: points (type, 4.4.3), usize (type, 4.5.5), sign (function, 4.16.8), compare_y (function, 4.6.2)
template< typename R >
closest_pair_result_t<R> impl_closest_pair(points<R> &pts, usize l, usize r) {
  constexpr R inf = std::numeric_limits< R >::infinity();
  using result_t = closest_pair_result_t<R>;

  auto comp = [](const result_t &lhs, const result_t &rhs) {
    return lhs.first < rhs.first;
  };

  if (r - l <= 1) {
    return {inf, {}};
  }

  usize m = (l + r) / 2;
  R x = pts[m].x();
  result_t result = std::min(impl_closest_pair(pts, l, m), impl_closest_pair(pts, m, r), comp);

  auto f = pts.begin();
  std::inplace_merge(f + l, f + m, f + r, compare_y<R>);

  points<R> ps;
  for (usize i = l; i < r; i++) {
    if (sign(std::abs(pts[i].x() - x) - result.first) >= 0) continue;

    for (usize j = 0; j < ps.size(); j++) {
      R dy = pts[i].y() - (*std::next(ps.rbegin(), j)).y();
      if (sign(dy - result.first) >= 0) break;

      auto &u = pts[i];
      auto &v = *std::next(ps.rbegin(), j);
      result = std::min(result, {std::abs(u - v), std::make_pair(u, v)}, comp);
    }

    ps.emplace_back(pts[i]);
  }

  return result;
}

// 依赖: points (type, 4.4.3), compare_x (function, 4.6.1)
// 参数: pts 为点集
// 返回: pair{距离, {点1, 点2}}
template< typename R >
closest_pair_result_t<R> closest_pair(points<R> pts) {
  constexpr R inf = std::numeric_limits< R >::infinity();
  if (pts.size() <= 1) {
    return {inf, {}};
  }

  std::sort(pts.begin(), pts.end(), compare_x<R>);

  return impl_closest_pair(pts, 0, pts.size());
}




