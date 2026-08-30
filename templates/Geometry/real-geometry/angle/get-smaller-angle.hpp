// 依赖: point (type, 4.4.3), pi (function, 4.5.2)
// 参数: a、b、c 为三个点，b 为角顶点
// 返回: 夹角 ∠ABC，范围 [0, π)
template< typename R >
R get_smaller_angle(const point<R> &a, const point<R> &b, const point<R> &c) {
  const point<R> u(a - b), v(c - b);
  R alpha = std::atan2(u.y(), u.x());
  R beta  = std::atan2(v.y(), v.x());

  if (alpha > beta) std::swap(alpha, beta);

  R theta = beta - alpha;
  return std::min(theta, 2 * pi() - theta);
}




