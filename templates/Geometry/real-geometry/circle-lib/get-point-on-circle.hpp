// 依赖: point (type, 4.4.3)
template< typename R >
point<R> point_on_circle(const point<R> &o, R r, R rad) { // 按圆心角求圆上某点
  return point<R>(o.x() + std::cos(rad) * r, o.y() + std::sin(rad) * r);
}



