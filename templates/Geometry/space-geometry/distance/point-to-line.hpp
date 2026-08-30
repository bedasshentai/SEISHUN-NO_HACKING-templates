// 依赖: point3d (class, 6.2.3), line3d (class, 6.2.1), dot3d (function, 6.5.2), distance3d/normalize3d (constant, 6.5.3), cross_norm3d (function, 6.5.4)
// 参数: p 为点，l 为直线
// 返回: pair{距离, 最近点}
template< typename R >
std::pair< R, point3d< R > > point_to_line3d(const point3d< R > &p, const line3d< R > &l) { // 点到直线的最近距离与最近点
  R d = cross_norm3d(p - l.a, l.a - l.b) / distance3d(l.a, l.b);
  R t = dot3d(p - l.a, l.a - l.b) / distance3d(l.a, l.b);
  point3d< R > foot = l.a + normalize3d(l.a - l.b) * t;
  return {d, foot};
}




