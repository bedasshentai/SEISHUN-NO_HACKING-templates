// 依赖: point3d (class, 6.2.3), line3d (class, 6.2.1), on_plane3d (function, 6.7.4), line_parallel3d (function, 6.7.1)
// 参数: l1、l2 为两条直线
// 返回: pair{是否相交, 交点}
template< typename R >
std::pair< bool, point3d< R > > line_intersection3d(const line3d< R > &l1, const line3d< R > &l2) { // 空间两直线相交及交点
  if (!on_plane3d(l1.a, l1.b, l2.a, l2.b) || line_parallel3d(l1, l2)) return {false, {}};
  point3d< R > s1 = l1.a, e1 = l1.b, s2 = l2.a, e2 = l2.b;
  point3d< R > o(0, 0, 0), z(0, 0, 1), y(0, 1, 0);
  R val = 0;
  if (!on_plane3d(l1.a, l1.b, o, z)) {
    val = ((s1.x - s2.x) * (s2.y - e2.y) - (s1.y - s2.y) * (s2.x - e2.x)) /
          ((s1.x - e1.x) * (s2.y - e2.y) - (s1.y - e1.y) * (s2.x - e2.x));
  } else if (!on_plane3d(l1.a, l1.b, o, y)) {
    val = ((s1.x - s2.x) * (s2.z - e2.z) - (s1.z - s2.z) * (s2.x - e2.x)) /
          ((s1.x - e1.x) * (s2.z - e2.z) - (s1.z - e1.z) * (s2.x - e2.x));
  } else {
    val = ((s1.y - s2.y) * (s2.z - e2.z) - (s1.z - s2.z) * (s2.y - e2.y)) /
          ((s1.y - e1.y) * (s2.z - e2.z) - (s1.z - e1.z) * (s2.y - e2.y));
  }
  return {true, s1 + (e1 - s1) * val};
}




