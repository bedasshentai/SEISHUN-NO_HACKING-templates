// 依赖: polygon (type, 4.4.4), usize (type, 4.5.5), cross_product (function, 4.13.2), next_idx (function, 4.16.4)
template< typename R >
R polygon_area(const polygon<R> &poly) {
  usize n = poly.size();

  R res = 0;
  for (usize i = 0; i < n; ++i) {
    res += cross_product(poly[i], poly[next_idx(i, n)]);
  }
  return res / 2;
}



