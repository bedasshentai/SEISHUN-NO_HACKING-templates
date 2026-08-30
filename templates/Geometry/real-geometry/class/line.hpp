// 依赖: point (type, 4.4.3), equals (function, 4.16.2)
template< typename R >
class line {
  using P = point<R>;

 public:
  P a, b;

  line() = default;
  line(P a, P b) : a(a), b(b) {
    assert(not equals(a, b));
  }

};

// 依赖: point (type, 4.4.3), equals (function, 4.16.2)
template< typename R >
using lines = std::vector< line<R> >;



