// 依赖: sign (function, 4.16.8)
template< typename R >
bool equals(R a, R b) {
  return sign(a - b) == 0;
}



