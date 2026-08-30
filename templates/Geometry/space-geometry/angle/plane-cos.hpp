// 依赖: plane3d (class, 6.2.2), dot3d (function, 6.5.2), length3d (function, 6.5.3), plane_normal (function, 6.5.4)
template< typename R >
R plane_cos(const plane3d< R > &s1, const plane3d< R > &s2) { // 两平面夹角 cos
  point3d< R > U = plane_normal(s1), V = plane_normal(s2);
  return dot3d(U, V) / length3d(U) / length3d(V);
}



