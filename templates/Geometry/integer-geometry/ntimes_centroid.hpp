// 依赖: lattice_point (class, 5.9), lattice_points (type, 5.10)
template< typename Z >
lattice_point< Z > ntimes_centroid(const lattice_points<Z> &pts) {
  return std::accumulate(pts.begin(), pts.end(), lattice_point<Z>(0, 0));
}



