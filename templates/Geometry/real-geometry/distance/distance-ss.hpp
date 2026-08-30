// 依赖: segment (class, 4.4.5), distance_sp (function, 4.9.5), intersect_ss (function, 4.15.3)
template< typename R >
R distance_ss(const segment<R> &s1, const segment<R> &s2) {
  if (intersect_ss(s1, s2)) return 0;
  R r1 = distance_sp(s1, s2.a);
  R r2 = distance_sp(s1, s2.b);
  R r3 = distance_sp(s2, s1.a);
  R r4 = distance_sp(s2, s1.b);
  return std::min({r1, r2, r3, r4});
}



