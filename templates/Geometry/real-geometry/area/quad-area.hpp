// 依赖: point (type, 4.4.3), cross_product (function, 4.13.2)
template< typename R >
R quad_area(const point<R> &u, const point<R> &v) { // 两向量构成的平面四边形有向面积
  return cross_product(u, v);
}



