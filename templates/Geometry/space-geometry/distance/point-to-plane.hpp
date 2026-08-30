// 依赖: point3d (class, 6.2.3), plane3d (class, 6.2.2), dot3d (function, 6.5.2), length3d (function, 6.5.3), plane_normal (function, 6.5.4)
// 参数: p 为点，s 为平面
// 返回: pair{距离, 最近点}
template< typename R >
std::pair< R, point3d< R > > point_to_plane3d(const point3d< R > &p, const plane3d< R > &s) { // 点到平面的最近距离与最近点
  point3d< R > vec = plane_normal(s);
  R val = dot3d(vec, p - s.u);
  R d = std::abs(val) / length3d(vec);
  point3d< R > foot = p - vec * (val / (length3d(vec) * length3d(vec)));
  return {d, foot};
}




