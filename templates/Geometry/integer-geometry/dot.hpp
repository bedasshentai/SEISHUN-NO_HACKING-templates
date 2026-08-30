// 依赖: lattice_point (class, 5.9)
template< typename Z >
Z dot(const lattice_point<Z> &a, const lattice_point<Z> &b) {
  return a.x() * b.x() + a.y() * b.y();
}



