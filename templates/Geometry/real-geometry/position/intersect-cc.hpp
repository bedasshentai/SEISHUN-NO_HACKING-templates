constexpr int SEPARATE     = 4;
constexpr int CIRCUMSCRIBE = 3;
constexpr int INTERSECT    = 2;
constexpr int INSCRIBE     = 1;
constexpr int CONTAIN      = 0;

// 依赖: circle (class, 4.4.1), equals (function, 4.16.1), sign (function, 4.16.8)
// 参数: c1、c2 为两个圆
// 返回: 非布尔：0 内含 / 1 内切 / 2 相交 / 3 外切 / 4 外离
template< typename R >
int intersect_cc(circle<R> c1, circle<R> c2) {
  if (c1.r > c2.r) std::swap(c1, c2);
  R d = std::abs(c1.o - c2.o), r = c1.r + c2.r;

  if (sign(d - r) > 0) return SEPARATE;
  if (sign(d + c1.r - c2.r) < 0) return CONTAIN;
  if (equals(d, r)) return CIRCUMSCRIBE;
  if (equals(d + c1.r, c2.r)) return INSCRIBE;
  return INTERSECT;
}





