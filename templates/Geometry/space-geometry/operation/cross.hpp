// 依赖: point3d (class, 6.2.3)
template< typename R >
point3d< R > cross3d(const point3d< R > &a, const point3d< R > &b) { // 叉乘
  return point3d< R >(a.y * b.z - a.z * b.y,
                      a.z * b.x - a.x * b.z,
                      a.x * b.y - a.y * b.x);
}



