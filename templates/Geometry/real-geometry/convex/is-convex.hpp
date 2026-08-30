// 依赖: polygon (type, 4.4.4), usize (type, 4.5.5), ccw (function, 4.13.1), next_idx (function, 4.16.4), prev_idx (function, 4.16.6)
template< typename R >
bool is_convex(const polygon<R> &poly) {
  usize n = poly.size();
  for (usize i = 0; i < n; i++) {
    if (ccw(poly[prev_idx(i, n)], poly[i], poly[next_idx(i, n)]) != -1) continue;
    return false;
  }
  return true;
}



