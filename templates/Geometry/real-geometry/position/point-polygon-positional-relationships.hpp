// O(N)
// 依赖: point (type, 4.4.3), polygon (type, 4.4.4), usize (type, 4.5.5), next_idx (function, 4.16.4), cross_product (function, 4.13.2), inner_product (function, 4.13.3), sign (function, 4.16.8), OUT/ON_EDGE/IN (constant, 4.12.3)
// 参数: p 为待判点，poly 为多边形
// 返回: 非布尔：0 外 / 1 边上 / 2 内
template< typename R >
int point_polygon_positional_relationships(const point<R> &p, const polygon<R> &poly) {
  usize n = poly.size();

  bool in = false;
  for (usize i = 0; i < n; i++) {
    usize j = next_idx(i, n);
    point<R> a = poly[i] - p, b = poly[j] - p;

    if (a.y() > b.y()) std::swap(a, b);

    if (a.y() <= 0 and 0 < b.y() and cross_product(a, b) < 0) {
      in = not in;
    }

    if (sign(cross_product(a, b)) == 0 and sign(inner_product(a, b)) <= 0) {
      return ON_EDGE;
    }
  }

  return in ? IN : OUT;
}





