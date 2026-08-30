// 依赖: point3d (class, 6.2.3), plane3d (class, 6.2.2), dot3d (function, 6.5.2), plane_normal (function, 6.5.4), sign (function, 4.16.8)
template< typename R >
bool point_on_plane_side3d(const point3d< R > &p1, const point3d< R > &p2, const plane3d< R > &s) { // 两点是否在平面同侧
  R val = dot3d(plane_normal(s), p1 - s.u) * dot3d(plane_normal(s), p2 - s.u);
  return sign(val) == 1;
}



