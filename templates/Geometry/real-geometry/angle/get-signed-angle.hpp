// 依赖: point (type, 4.4.3), pi (function, 4.5.2)
// 参数: a、b、c 为三个点，b 为角顶点
// 返回: 有向角 ∠ABC，范围 [0, 2π)
template< typename R >
R get_signed_angle(const point<R> &a, const point<R> &b, const point<R> &c) {
  auto fix = [](R theta) {
    if (theta < 0) theta += 2 * pi();
    return theta;
  };

  const point<R> u(a - b), v(c - b);
  R alpha = fix(std::atan2(u.y(), u.x()));
  R beta  = fix(std::atan2(v.y(), v.x()));
  return fix(beta - alpha);
}




