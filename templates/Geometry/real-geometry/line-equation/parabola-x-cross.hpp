// 依赖: sign (function, 4.16.8)
// 参数: a、b、c 为 ax²+bx+c 系数
// 返回: tuple{count,x1,x2}：count 0 无 / 1 相切 / 2 两个交点
template< typename R >
std::tuple< int, R, R > parabola_x_cross(R a, R b, R c) { // a x^2 + b x + c 与 x 轴交点
  R disc = b * b - a * c * 4;
  if (disc < 0) return {0, 0, 0};
  R d = std::sqrt(disc);
  R x1 = -(d + b) / 2 / a;
  R x2 = (d - b) / 2 / a;
  if (x1 > x2) std::swap(x1, x2);
  if (sign(disc) == 0) return {1, x2, 0};
  return {2, x1, x2};
}




