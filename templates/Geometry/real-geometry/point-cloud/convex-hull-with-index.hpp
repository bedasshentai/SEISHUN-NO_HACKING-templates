// 依赖: point (type, 4.4.3), points (type, 4.4.3), polygon (type, 4.4.4), usize (type, 4.5.5), compare_x (function, 4.6.1), cross_product (function, 4.13.2), sign (function, 4.16.8)
// 参数: pts 为点集
// 返回: pair{凸包, 顶点原下标}
template< typename R >
std::pair< polygon<R>, std::vector< usize > > convex_hull_with_index(const points<R> &pts) {
  usize n = pts.size();
  if (n <= 2) {
    std::vector< usize > idxs(n);
    std::iota(idxs.begin(), idxs.end(), 0);
    return {pts, idxs};
  }

  std::vector< std::pair< point<R>, usize > > ps;
  ps.reserve(n);
  for (usize i = 0; i < n; i++) {
    ps.emplace_back(pts[i], i);
  }

  auto cmp = [](const std::pair<point<R>, usize> &a, const std::pair<point<R>, usize> &b) {
    return compare_x(a.first, b.first);
  };
  std::sort(ps.begin(), ps.end(), cmp);

  std::vector< usize > idxs(2 * n);
  polygon<R> poly(2 * n);
  usize k = 0, i = 0;

  auto check = [&](usize i) {
    return sign(cross_product<R>(poly[k - 1] - poly[k - 2], ps[i].first - poly[k - 1])) == -1;
  };

  while (i < n) {
    while (k >= 2 and check(i)) k--;

    std::tie(poly[k], idxs[k]) = ps[i];
    k++; i++;
  }

  i = n - 2;
  usize t = k + 1;
  while (true) {
    while (k >= t and check(i)) k--;

    std::tie(poly[k], idxs[k]) = ps[i];
    k++;
    if (not i) break;
    i--;
  }

  poly.resize(k - 1);
  idxs.resize(k - 1);
  return {poly, idxs};
}




