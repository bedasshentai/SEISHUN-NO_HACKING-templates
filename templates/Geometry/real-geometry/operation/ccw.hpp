// 依赖: point (type, 4.4.3), sign (function, 4.16.8), cross_product (function, 4.13.2), inner_product (function, 4.13.3), COUNTER_CLOCKWISE/CLOCKWISE/ONLINE_BACK/ONLINE_FRONT/ON_SEGMENT (constant, 4.12.1)
// 参数: a、b、c 为三个点（有顺序）
// 返回: 非布尔：+1 逆时针 / -1 顺时针 / +2 共线且 c 在 a-b 延长线 / -2 共线且 c 在前方 / 0 共线且 c 在线段上
template< typename R >
int ccw(const point<R> &a, point<R> b, point<R> c) {
  b = b - a, c = c - a;
  if (sign(cross_product(b, c)) == +1) return COUNTER_CLOCKWISE;
  if (sign(cross_product(b, c)) == -1) return CLOCKWISE;
  if (sign(inner_product(b, c)) == -1) return ONLINE_BACK;
  if (std::norm(b) < std::norm(c)) return ONLINE_FRONT;
  return ON_SEGMENT;
}





