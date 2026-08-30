// 依赖: point3d (class, 6.2.3), line3d (class, 6.2.1), cross_norm3d (function, 6.5.4), sign (function, 4.16.8)
template< typename R >
bool point_on_segment3d(const point3d< R > &p, const line3d< R > &l) { // 端点也算
  return sign(cross_norm3d(p - l.a, p - l.b)) == 0 &&
         std::min(l.a.x, l.b.x) <= p.x && p.x <= std::max(l.a.x, l.b.x) &&
         std::min(l.a.y, l.b.y) <= p.y && p.y <= std::max(l.a.y, l.b.y) &&
         std::min(l.a.z, l.b.z) <= p.z && p.z <= std::max(l.a.z, l.b.z);
}

template< typename R >
bool point_on_segment_ex3d(const point3d< R > &p, const line3d< R > &l) { // 端点不算
  return point_on_segment3d(p, l) && p != l.a && p != l.b;
}



