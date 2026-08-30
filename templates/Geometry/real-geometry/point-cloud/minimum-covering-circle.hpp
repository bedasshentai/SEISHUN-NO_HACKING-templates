// 依赖: point (type, 4.4.3), points (type, 4.4.3), circle (class, 4.4.1), in_circle (function, 4.15.1), circumscribed_circle (function, 4.3.1)
// 参数: pts 为点集，seed 为随机种子
// 返回: 最小覆盖圆
template< typename R >
circle<R> minimum_covering_circle(points<R> pts, unsigned int seed) {
  auto make_circle = [](const point<R> &a, const point<R> &b) {
    return circle<R>(point<R>(a + b) * 0.5, abs(a - b) * 0.5);
  };

  int n = pts.size();
  if (n == 1) return circle<R>(pts[0], 0);

  std::mt19937 engine(seed);
  std::shuffle(pts.begin(), pts.end(), engine);
  circle<R> res(point<R>(), -1);

  for (int i = 0; i < n; i++) {
    if (in_circle(res, pts[i])) continue;
    res = circle<R>(pts[i], 0);

    for (int j = 0; j < i; j++) {
      if (in_circle(res, pts[j])) continue;
      res = make_circle(pts[i], pts[j]);

      for (int k = 0; k < j; k++) {
        if (in_circle(res, pts[k])) continue;
        res = circumscribed_circle(pts[i], pts[j], pts[k]);
      }
    }
  }

  return res;
}




