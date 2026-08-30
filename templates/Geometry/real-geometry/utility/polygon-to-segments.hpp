// 依赖: polygon (type, 4.4.4), segment (class, 4.4.5), usize (type, 4.5.5), next_idx (function, 4.16.4)
template< typename R >
segments<R> polygon_to_segments(const polygon<R> &poly) {
  usize n = poly.size();

  segments<R> segs(n);
  for (usize i = 0; i < n; i++) {
    segs[i] = segment<R>(poly[i], poly[next_idx(i, n)]);
  }

  return segs;
}



