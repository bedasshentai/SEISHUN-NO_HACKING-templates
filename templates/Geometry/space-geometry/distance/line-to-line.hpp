// 依赖: point3d (class, 6.2.3), line3d (class, 6.2.1), cross3d (function, 6.5.1), dot3d (function, 6.5.2), length3d (function, 6.5.3)
// 参数: l1、l2 为两条直线
// 返回: tuple{距离, l1 最近点, l2 最近点}
template< typename R >
std::tuple< R, point3d< R >, point3d< R > > line_to_line3d(const line3d< R > &l1, const line3d< R > &l2) { // 两直线最近距离与最近点对
  point3d< R > vec = cross3d(l1.a - l1.b, l2.a - l2.b);
  R d = std::abs(dot3d(l1.a - l2.a, vec)) / length3d(vec);
  point3d< R > U = l1.b - l1.a, V = l2.b - l2.a;
  vec = cross3d(U, V);
  R p = dot3d(vec, vec);
  R t1 = dot3d(cross3d(l2.a - l1.a, V), vec) / p;
  R t2 = dot3d(cross3d(l2.a - l1.a, U), vec) / p;
  return {d, l1.a + (l1.b - l1.a) * t1, l2.a + (l2.b - l2.a) * t2};
}




