// 依赖: point3d (class, 6.2.3), cross3d (function, 6.5.1), dot3d (function, 6.5.2), point_on_triangle3d (function, 6.6.1), sign (function, 4.16.8)
// 参数: l、r 为线段两端点，p1、p2、p3 为三角形三顶点
// 返回: pair{是否相交, 交点}
template< typename R >
std::pair< bool, point3d< R > > segment_triangle_cross(const point3d< R > &l, const point3d< R > &r,
                                                       const point3d< R > &p1, const point3d< R > &p2, const point3d< R > &p3) { // 线段与空间三角形相交及交点
  point3d< R > x = cross3d(p2 - p1, p3 - p1);
  if (sign(dot3d(x, r - l)) == 0) return {false, {}};
  R t = dot3d(x, p1 - l) / dot3d(x, r - l);
  if (t < 0 || t - 1 > 0) return {false, {}};
  point3d< R > hit = l + (r - l) * t;
  if (point_on_triangle3d(hit, p1, p2, p3)) return {true, hit};
  return {false, {}};
}




