// 依赖: point3d (class, 6.2.3), cross3d (function, 6.5.1), dot3d (function, 6.5.2)
// 参数: a、b、c、d 为四个顶点
// 返回: 四面体体积
template< typename R >
R tetrahedron_volume(const point3d< R > &a, const point3d< R > &b, const point3d< R > &c, const point3d< R > &d) { // 四面体体积
  return std::abs(dot3d(d - a, cross3d(b - a, c - a))) / 6;
}




