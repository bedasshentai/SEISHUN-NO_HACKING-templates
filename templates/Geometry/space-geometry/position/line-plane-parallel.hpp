// 依赖: line3d (class, 6.2.1), plane3d (class, 6.2.2), dot3d (function, 6.5.2), plane_normal (function, 6.5.4), sign (function, 4.16.8)
template< typename R >
bool line_plane_parallel3d(const line3d< R > &l, const plane3d< R > &s) { // 直线是否与平面平行
  return sign(dot3d(l.a - l.b, plane_normal(s))) == 0;
}



