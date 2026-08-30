// 依赖: circle (class, 4.4.1), point (type, 4.4.3), sign (function, 4.16.8)
template< typename R >
bool in_circle(const circle<R> &c, const point<R> &p) {
  return sign(std::abs(c.o - p) - c.r) == -1;
}



