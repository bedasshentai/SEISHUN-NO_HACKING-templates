// circle

// 依赖: point (type, 4.4.3)
template< typename R >
class circle {
 public:
  point<R> o;
  R r;

  circle() = default;
  circle(point<R> o, R r) : o(o), r(r) {}

  const point<R> center() const {
    return o;
  }

  const R radius() const {
    return r;
  }
};

// 依赖: point (type, 4.4.3)
template< typename R >
using circles = std::vector< circle<R> >;



