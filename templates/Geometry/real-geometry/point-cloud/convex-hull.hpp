// 依赖: points (type, 4.4.3), polygon (type, 4.4.4), usize (type, 4.5.5), isize (type, 4.5.5), compare_x (function, 4.6.1), cross_product (function, 4.13.2), sign (function, 4.16.8)
template< typename R >
polygon<R> convex_hull(points<R> pts) {
  usize n = pts.size(), k = 0;
  if (n <= 2) return pts;

  std::sort(pts.begin(), pts.end(), compare_x<R>);
  polygon<R> res(2 * n);

  auto check = [&](usize i) {
    return sign(cross_product<R>(res[k - 1] - res[k - 2], pts[i] - res[k - 1])) == -1;
  };

  for (usize i = 0; i < n; res[k++] = pts[i++]) {
    while (k >= 2 and check(i)) --k;
  }

  usize t = k + 1;
  for (isize i = n - 2; i >= 0; res[k++] = pts[i--]) {
    while (k >= t and check(i)) --k;
  }

  res.resize(k - 1);
  return res;
}



