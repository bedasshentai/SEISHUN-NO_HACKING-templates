// warning: to use degree_to_radian<R>(deg)
//          if type of deg is `int`
// 依赖: pi (function, 4.5.2)
template< typename R >
R degree_to_radian(R deg) {
  return deg * pi() / 180.0;
}



