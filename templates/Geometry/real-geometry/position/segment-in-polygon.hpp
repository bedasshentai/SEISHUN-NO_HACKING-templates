// 依赖: point (type, 4.4.3), line (class, 4.4.2), segment (class, 4.4.5), polygon (type, 4.4.4), cross_point_ss (function, 4.8.5), cross_product (function, 4.13.2), point_on_line_left (function, 4.15.9), point_on_segment (function, 4.15.11), point_polygon_positional_relationships (function, 4.15.12)
template< typename R >
bool segment_in_polygon(const segment<R> &seg, const polygon<R> &poly) { // 线段是否在任意多边形内部
  int n = poly.size();
  line<R> l(seg.a, seg.b);

  auto inside = [&](const point<R> &p) {
    return point_polygon_positional_relationships(p, poly) != 0; // 0 = OUT
  };
  if (!inside(l.a) || !inside(l.b)) return false;

  auto L = [&](const point<R> &x, const line<R> &y) { return point_on_line_left(x, y); };

  for (int i = 0; i < n; i++) {
    point<R> u = poly[i], v = poly[(i + 1) % n], w = poly[(i + 2) % n];
    auto [t, p1, p2] = cross_point_ss(seg, segment<R>(u, v));
    if (t == 1) return false;
    if (t == 0) continue;
    if (t == 2) {
      if (point_on_segment(v, seg) && v != l.a && v != l.b) {
        if (cross_product<R>(v - u, w - v) > 0) return false;
      }
    } else { // t == 3
      if (p1 != u && p1 != v) {
        if (L(l.a, line<R>(v, u)) || L(l.b, line<R>(v, u))) return false;
      } else if (p1 == v) {
        if (l.a == v) {
          if (L(u, l)) {
            if (L(w, l) && L(w, line<R>(u, v))) return false;
          } else {
            if (L(w, l) || L(w, line<R>(u, v))) return false;
          }
        } else if (l.b == v) {
          if (L(u, line<R>(l.b, l.a))) {
            if (L(w, line<R>(l.b, l.a)) && L(w, line<R>(u, v))) return false;
          } else {
            if (L(w, line<R>(l.b, l.a)) || L(w, line<R>(u, v))) return false;
          }
        } else {
          if (L(u, l)) {
            if (L(w, line<R>(l.b, l.a)) || L(w, line<R>(u, v))) return false;
          } else {
            if (L(w, l) || L(w, line<R>(u, v))) return false;
          }
        }
      }
    }
  }
  return true;
}



