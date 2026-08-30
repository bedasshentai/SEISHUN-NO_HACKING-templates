// 依赖: lattice_point (class, 5.9)
template< typename Z >
class lattice_circle {
  lattice_point< Z > center_;
  Z r_;

 public:
  lattice_circle() {}
  lattice_circle(lattice_point< Z > center_, Z r_) : center_(center_), r_(r_) {}

  lattice_point< Z > center() const { return center_; }
  Z r() const { return r_; }
};



