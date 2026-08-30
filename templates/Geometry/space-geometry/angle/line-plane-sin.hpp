// 依赖: line3d (class, 6.2.1), plane3d (class, 6.2.2), dot3d (function, 6.5.2), length3d (function, 6.5.3), plane_normal (function, 6.5.4)
template< typename R >
R line_plane_sin(const line3d< R > &l, const plane3d< R > &s) { // 直线与平面夹角 sin
  point3d< R > vec = plane_normal(s);
  return dot3d(l.a - l.b, vec) / length3d(l.a - l.b) / length3d(vec);
}



