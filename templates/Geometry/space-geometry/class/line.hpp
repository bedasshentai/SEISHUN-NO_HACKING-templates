// 依赖: point3d (class, 6.2.3)
template< typename R >
struct line3d {
  point3d< R > a, b;
  line3d() = default;
  line3d(point3d< R > a_, point3d< R > b_) : a(a_), b(b_) {}
};



