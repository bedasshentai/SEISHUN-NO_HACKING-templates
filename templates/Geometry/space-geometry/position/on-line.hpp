// 依赖: point3d (class, 6.2.3), plane3d (class, 6.2.2), cross_norm3d (function, 6.5.4), sign (function, 4.16.8)
template< typename R >
bool on_line3d(const point3d< R > &a, const point3d< R > &b, const point3d< R > &c) { // 三点共线
  return sign(cross_norm3d(a - b, c - b)) == 0;
}

template< typename R >
bool on_line3d(const plane3d< R > &s) { return on_line3d(s.u, s.v, s.w); }



