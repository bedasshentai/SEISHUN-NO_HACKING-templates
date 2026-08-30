// 依赖: circle (class, 4.4.1), point (type, 4.4.3), points (type, 4.4.3), cross_point_cc (function, 4.8.1)
template< typename R >
points<R> tangent_cp(const circle<R> &c, const point<R> &p) {
  circle<R> t{p, std::sqrt(std::norm(c.o - p) - std::norm(c.r))};

  return cross_point_cc(c, t);
}



