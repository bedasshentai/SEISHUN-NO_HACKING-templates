// 依赖: point (type, 4.4.3), equals (function, 4.16.2)
template< typename R >
class segment {
 public:
  point<R> a, b;

  segment() = default;
  segment(point<R> a, point<R> b) : a(a), b(b) {
    assert(not equals(a, b));
  }

};

// 依赖: point (type, 4.4.3), equals (function, 4.16.2)
template< typename R >
using segments = std::vector< segment<R> >;



