// 依赖: point3d (class, 6.2.3), line3d (class, 6.2.1), plane3d (class, 6.2.2), dot3d (function, 6.5.2), plane_normal (function, 6.5.4), line_plane_parallel3d (function, 6.7.2)
// 参数: l 为直线，s 为平面
// 返回: pair{是否相交, 交点}
template< typename R >
std::pair< bool, point3d< R > > line_plane_cross(const line3d< R > &l, const plane3d< R > &s) { // 直线与平面相交及交点
  if (line_plane_parallel3d(l, s)) return {false, {}};
  point3d< R > vec = plane_normal(s);
  R val = dot3d(vec, s.u - l.a) / dot3d(vec, l.b - l.a);
  return {true, l.a + (l.b - l.a) * val};
}




