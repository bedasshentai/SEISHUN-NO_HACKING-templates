// 依赖: polygon (type, 4.4.4), usize (type, 4.5.5), compare_x (function, 4.6.1), sign (function, 4.16.8), cross_product (function, 4.13.2), next_idx (function, 4.16.4)
template< typename R >
R convex_diameter(const polygon<R> &poly) {
  usize n = poly.size();

  if (n == 2) return std::abs(poly[0] - poly[1]);

  usize i = 0, j = 0;
  for (usize k = 0; k < n; k++) {
    if (    compare_x(poly[i], poly[k])) i = k;
    if (not compare_x(poly[j], poly[k])) j = k;
  }

  R res{0};
  usize s = i, t = j;
  while (i != t or j != s) {
    res = std::max(res, std::abs(poly[i] - poly[j]));
    auto u = poly[next_idx(i, n)] - poly[i];
    auto v = poly[next_idx(j, n)] - poly[j];
    if (sign(cross_product<R>(u, v)) == -1) {
      i = next_idx(i, n);
    } else {
      j = next_idx(j, n);
    }
  }

  return res;
}



