// 依赖: point3d (class, 6.2.3), segment_triangle_cross (function, 6.6.2)
template< typename R >
bool triangle_intersection3d(const std::vector< point3d< R > > &a, const std::vector< point3d< R > > &b) { // 空间三角形是否相交
  for (int i = 0; i < 3; i++) {
    if (segment_triangle_cross(b[i], b[(i + 1) % 3], a[0], a[1], a[2]).first) return true;
    if (segment_triangle_cross(a[i], a[(i + 1) % 3], b[0], b[1], b[2]).first) return true;
  }
  return false;
}



