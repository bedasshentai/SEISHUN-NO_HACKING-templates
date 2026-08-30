// 依赖: line3d (class, 6.2.1), dot3d (function, 6.5.2), cross_norm3d (function, 6.5.4), sign (function, 4.16.8)
template< typename R >
bool line_parallel3d(const line3d< R > &l1, const line3d< R > &l2) {
  return sign(cross_norm3d(l1.a - l1.b, l2.a - l2.b)) == 0;
}

template< typename R >
bool line_vertical3d(const line3d< R > &l1, const line3d< R > &l2) {
  return sign(dot3d(l1.a - l1.b, l2.a - l2.b)) == 0;
}



