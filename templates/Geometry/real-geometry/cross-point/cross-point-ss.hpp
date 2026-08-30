// 依赖: point (type, 4.4.3), segment (class, 4.4.5), cross_point_ll (function, 4.8.4), cross_product (function, 4.13.2), sign (function, 4.16.8)
// 参数: s1、s2 为两条线段
// 返回: tuple{type,p1,p2}：type 0 不相交 / 1 严格相交一点 / 2 重叠(后两项为重叠段两端) / 3 端点相触
template< typename R >
std::tuple< int, point<R>, point<R> > cross_point_ss(const segment<R> &l1, const segment<R> &l2) {
  point<R> s1 = l1.a, e1 = l1.b, s2 = l2.a, e2 = l2.b;
  R A = std::max(s1.x(), e1.x()), AA = std::min(s1.x(), e1.x());
  R B = std::max(s1.y(), e1.y()), BB = std::min(s1.y(), e1.y());
  R C = std::max(s2.x(), e2.x()), CC = std::min(s2.x(), e2.x());
  R D = std::max(s2.y(), e2.y()), DD = std::min(s2.y(), e2.y());
  if (A < CC || C < AA || B < DD || D < BB) return {0, {}, {}};

  if (sign(cross_product<R>(e1 - s1, e2 - s2)) == 0) { // 平行
    if (sign(cross_product<R>(s2 - s1, e1 - s1)) != 0) return {0, {}, {}};
    point<R> p1(std::max(AA, CC), std::max(BB, DD));
    point<R> p2(std::min(A, C), std::min(B, D));
    if (p1 == p2) return {3, p1, p2};
    return {2, p1, p2};
  }

  R cp1 = cross_product<R>(s2 - s1, e2 - s1);
  R cp2 = cross_product<R>(s2 - e1, e2 - e1);
  R cp3 = cross_product<R>(s1 - s2, e1 - s2);
  R cp4 = cross_product<R>(s1 - e2, e1 - e2);
  if (sign(cp1 * cp2) == 1 || sign(cp3 * cp4) == 1) return {0, {}, {}};

  point<R> p = cross_point_ll(line<R>(l1.a, l1.b), line<R>(l2.a, l2.b));
  if (sign(cp1) != 0 && sign(cp2) != 0 && sign(cp3) != 0 && sign(cp4) != 0) return {1, p, p};
  return {3, p, p};
}





