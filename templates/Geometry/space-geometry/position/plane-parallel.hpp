// 依赖: plane3d (class, 6.2.2), dot3d (function, 6.5.2), plane_normal/cross_norm3d (constant, 6.5.4), sign (function, 4.16.8)
template< typename R >
bool plane_parallel3d(const plane3d< R > &s1, const plane3d< R > &s2) {
  return sign(cross_norm3d(plane_normal(s1), plane_normal(s2))) == 0;
}

template< typename R >
bool plane_vertical3d(const plane3d< R > &s1, const plane3d< R > &s2) {
  return sign(dot3d(plane_normal(s1), plane_normal(s2))) == 0;
}



