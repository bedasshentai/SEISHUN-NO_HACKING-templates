// 依赖: line3d (class, 6.2.1), line_parallel3d (function, 6.7.1)
template< typename R >
bool same_line3d(const line3d< R > &l1, const line3d< R > &l2) { // 两直线是否同一条
  return line_parallel3d(l1, l2) &&
         line_parallel3d(line3d< R >(l1.a, l2.b), line3d< R >(l1.b, l2.a));
}



