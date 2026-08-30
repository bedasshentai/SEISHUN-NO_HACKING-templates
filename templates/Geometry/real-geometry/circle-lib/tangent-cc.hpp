// 依赖: circle (class, 4.4.1), point (type, 4.4.3), lines (type, 4.4.2), sign (function, 4.16.8)
template< typename R >
lines<R> tangent_cc(circle<R> a, circle<R> b) {
  lines<R> ls;
  if (a.r > b.r) std::swap(a, b);

  auto d = a.o - b.o;
  R g = norm(d);

  if (sign(g) == 0) return ls;

  point<R> u = d / std::sqrt(g);
  point<R> v(-u.y(), u.x());

  for (int s = 1; s >= -1; s -= 2) {
    R h = (a.r * s + b.r) / std::sqrt(g);

    auto dh = 1 - std::norm(h);
    if (sign(dh) == 0) {
      ls.emplace_back(b.o + u * b.r, b.o + (u + v) * b.r);
    }

    else if (sign(dh) > 0) {
      auto uu = u * h;
      auto vv = v * std::sqrt(dh);
      ls.emplace_back(b.o + (uu + vv) * b.r, a.o - (uu + vv) * a.r * (R)s);
      ls.emplace_back(b.o + (uu - vv) * b.r, a.o - (uu - vv) * a.r * (R)s);
    }
  }

  return ls;
}



