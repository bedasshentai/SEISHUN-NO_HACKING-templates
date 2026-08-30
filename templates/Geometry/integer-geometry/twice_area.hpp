// 依赖: lattice_polygon (type, 5.12), det (function, 5.4), nidx (function, 5.7), usize (type, 5.1)
template< typename Z >
Z twice_signed_area(const lattice_polygon<Z> &poly) {
  Z s = Z(0);
  for (usize i = 0; i < poly.size(); i++) {
    s += det(poly[i], poly[nidx(i, poly.size())]);
  }
  return s;
}

// 依赖: lattice_polygon (type, 5.12)
// 参数: poly 为格点多边形
// 返回: 有向/无向面积×2
template< typename Z >
Z twice_unsigned_area(const lattice_polygon<Z> &poly) {
  return abs(twice_signed_area(poly));
}




