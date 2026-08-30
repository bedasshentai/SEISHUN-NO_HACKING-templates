// 依赖: plane3d (class, 6.2.2), on_plane3d (function, 6.7.4)
template< typename R >
bool same_plane3d(const plane3d< R > &s1, const plane3d< R > &s2) { // 两平面是否同一个
  return on_plane3d(s1.u, s2.u, s2.v, s2.w) &&
         on_plane3d(s1.v, s2.u, s2.v, s2.w) &&
         on_plane3d(s1.w, s2.u, s2.v, s2.w);
}



