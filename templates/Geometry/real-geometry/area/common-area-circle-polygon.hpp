// 依赖: circle (class, 4.4.1), segment (class, 4.4.5), point (type, 4.4.3), points (type, 4.4.3), usize (type, 4.5.5), cross_product (function, 4.13.2), inner_product (function, 4.13.3), sign (function, 4.16.8), distance_sp (function, 4.9.5), cross_point_cl (function, 4.8.2), equals (function, 4.16.2)
template< typename R >
R impl_common_area_ca_cp(const circle<R> &c, const segment<R> &s) {
  point<R> va = c.o - s.a, vb = c.o - s.b;
  R f = cross_product(va, vb), res = 0;

  if (sign(f) == 0) return res;
  if (sign(std::max(std::abs(va), std::abs(vb)) - c.r) <= 0) return f;

  point<R> d(inner_product(va, vb), cross_product(va, vb));
  if (sign(distance_sp(s, c.o) - c.r) >= 0) {
    return std::norm(c.r) * std::atan2(d.y(), d.x());
  }

  points<R> ps = cross_point_cl(c, {s.a, s.b});
  if (ps.empty()) return res;
  if (ps.size() == 2 and sign(inner_product<R>(ps[1] - ps[0], s.a - ps[0])) >= 0) {
    std::swap(ps[0], ps[1]);
  }

  ps.emplace(ps.begin(), s.a);
  ps.emplace_back(s.b);
  for (usize i = 1; i < ps.size(); i++) {
    if (equals(ps[i - 1], ps[i])) continue;
    res += impl_common_area_ca_cp(c, {ps[i - 1], ps[i]});
  }

  return res;
}

// 依赖: circle (class, 4.4.1), polygon (type, 4.4.4), usize (type, 4.5.5), polygon_to_segments (function, 4.16.5)
template< typename R >
R common_area_circle_polygon(const circle<R> &c, const polygon<R> &p) {
  usize n = p.size();
  if (n < 3) return 0;

  auto segs = polygon_to_segments(p);

  R res = 0;
  for (auto &seg: segs) {
    res += impl_common_area_ca_cp(c, seg);
  }

  return res / 2;
}



