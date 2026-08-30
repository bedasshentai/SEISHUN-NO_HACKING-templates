// 依赖: point3d (class, 6.2.3)
template< typename R >
struct plane3d {
  point3d< R > u, v, w; // 三个点确定一个平面
  plane3d() = default;
  plane3d(point3d< R > u_, point3d< R > v_, point3d< R > w_) : u(u_), v(v_), w(w_) {}
};



