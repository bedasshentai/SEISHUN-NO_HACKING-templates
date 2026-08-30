// 依赖: lattice_point (class, 5.9), det (function, 5.4)
template< typename Z >
bool argcmp(const lattice_point<Z> &a, const lattice_point<Z> &b) {
  using std::pair;
  bool fa = pair(a.y(), a.x()) < pair<Z, Z>(0, 0);
  bool fb = pair(b.y(), b.x()) < pair<Z, Z>(0, 0);
  Z d = det(a, b);
  return fa != fb ? fa < fb : (d == 0 ? a.norm() < b.norm() : d > 0);
}



