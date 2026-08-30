// 依赖: lattice_point (class, 5.9), lattice_polygon (type, 5.12), twice_unsigned_area (function, 5.13)
// 参数: p 为格点多边形
// 返回: 边上/内部网格点个数
template< typename Z >
Z on_grid_count(const lattice_polygon< Z > &p) { // 多边形边上的网格点个数
  Z ans = 0;
  int n = static_cast< int >(p.size());
  for (int i = 0; i < n; i++) {
    auto a = p[i], b = p[(i + 1) % n];
    ans += std::gcd(std::abs(a.x() - b.x()), std::abs(a.y() - b.y()));
  }
  return ans;
}

template< typename Z >
Z in_grid_count(const lattice_polygon< Z > &p) { // 多边形内(不含边)的网格点个数（Pick 定理）
  Z area2 = twice_unsigned_area(p);
  return (area2 - on_grid_count(p)) / 2 + 1;
}




