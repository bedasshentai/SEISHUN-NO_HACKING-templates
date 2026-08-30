// 依赖: segment (class, 4.4.5), ccw (function, 4.13.1)
template< typename R >
bool intersect_ss(const segment<R> &s1, const segment<R> &s2) {
  return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and
         ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
}



