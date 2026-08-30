// 依赖: plane3d (class, 6.2.2), cross3d (function, 6.5.1), length3d (function, 6.5.3)
template< typename R >
point3d< R > plane_normal(const plane3d< R > &s) { // 平面法向量
  return cross3d(s.u - s.v, s.v - s.w);
}

template< typename R >
R cross_norm3d(const point3d< R > &a, const point3d< R > &b) { // 叉乘的模
  return length3d(cross3d(a, b));
}



