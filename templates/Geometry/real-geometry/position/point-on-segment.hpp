// 依赖: point (type, 4.4.3), segment (class, 4.4.5), cross_product (function, 4.13.2), sign (function, 4.16.8)
template< typename R >
bool point_on_segment(const point<R> &p, const segment<R> &s) { // 端点也算
  return sign(cross_product<R>(p - s.a, p - s.b)) == 0 &&
         std::min(s.a.x(), s.b.x()) <= p.x() && p.x() <= std::max(s.a.x(), s.b.x()) &&
         std::min(s.a.y(), s.b.y()) <= p.y() && p.y() <= std::max(s.a.y(), s.b.y());
}

template< typename R >
bool point_on_segment_ex(const point<R> &p, const segment<R> &s) { // 端点不算
  return point_on_segment(p, s) && p != s.a && p != s.b;
}



