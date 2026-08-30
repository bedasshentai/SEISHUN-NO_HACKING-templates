// 依赖: line3d (class, 6.2.1), on_line3d (function, 6.7.3), on_plane3d (function, 6.7.4), point_on_segment3d (function, 6.7.6), point_on_segment_side3d (function, 6.7.8)
template< typename R >
bool segment_intersection3d(const line3d< R > &l1, const line3d< R > &l2) { // 重叠、端点相交均视为相交
  if (!on_plane3d(l1.a, l1.b, l2.a, l2.b)) return false; // 不共面
  if (!on_line3d(l1.a, l1.b, l2.a) || !on_line3d(l1.a, l1.b, l2.b)) {
    return !point_on_segment_side3d(l1.a, l1.b, l2) && !point_on_segment_side3d(l2.a, l2.b, l1);
  }
  return point_on_segment3d(l1.a, l2) || point_on_segment3d(l1.b, l2) ||
         point_on_segment3d(l2.a, l1) || point_on_segment3d(l2.b, l1);
}



