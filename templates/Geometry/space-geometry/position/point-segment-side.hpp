// 依赖: point3d (class, 6.2.3), line3d (class, 6.2.1), cross3d (function, 6.5.1), dot3d (function, 6.5.2), on_plane3d (function, 6.7.4), sign (function, 4.16.8)
template< typename R >
bool point_on_segment_side3d(const point3d< R > &p1, const point3d< R > &p2, const line3d< R > &l) { // 两点是否在线段同侧
  if (!on_plane3d(p1, p2, l.a, l.b)) return false; // 不共面
  R val = dot3d(cross3d(l.a - l.b, p1 - l.b), cross3d(l.a - l.b, p2 - l.b));
  return sign(val) == 1;
}



