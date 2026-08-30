// 依赖: point3d (class, 6.2.3)
template< typename R >
R dot3d(const point3d< R > &a, const point3d< R > &b) { // 点乘
  return a.x * b.x + a.y * b.y + a.z * b.z;
}



