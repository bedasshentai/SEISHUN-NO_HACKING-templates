// 依赖: eps (function, 4.5.1), PLUS/ZERO/MINUS (constant, 4.12.5)
template< typename R >
inline int sign(R r) {
  if (r < -eps()) return MINUS;
  if (r > +eps()) return PLUS;
  return ZERO;
}



