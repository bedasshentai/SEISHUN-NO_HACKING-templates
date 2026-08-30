// 依赖: point3d (class, 6.2.3), line3d (class, 6.2.1), point_on_segment_side3d (function, 6.7.8)
template< typename R >
bool point_on_triangle3d(const point3d< R > &p, const point3d< R > &a, const point3d< R > &b, const point3d< R > &c) { // 点是否在空间三角形上
  return point_on_segment_side3d(p, a, line3d< R >(b, c)) &&
         point_on_segment_side3d(p, b, line3d< R >(a, c)) &&
         point_on_segment_side3d(p, c, line3d< R >(a, b));
}



