// 依赖: line3d (class, 6.2.1), dot3d (function, 6.5.2), length3d (function, 6.5.3)
template< typename R >
R line_cos(const line3d< R > &l1, const line3d< R > &l2) { // 两直线夹角 cos
  return dot3d(l1.a - l1.b, l2.a - l2.b) / length3d(l1.a - l1.b) / length3d(l2.a - l2.b);
}



