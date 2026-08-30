// 依赖: point3d (class, 6.2.3), plane3d (class, 6.2.2), dot3d (function, 6.5.2), plane_normal (function, 6.5.4), sign (function, 4.16.8)
template< typename R >
bool on_plane3d(const point3d< R > &a, const point3d< R > &b, const point3d< R > &c, const point3d< R > &d) { // 四点共面
  return sign(dot3d(plane_normal(plane3d< R >(a, b, c)), d - a)) == 0;
}



