// 依赖: point (type, 4.4.3), line (class, 4.4.2)
template< typename R >
R slope(const point<R> &p1, const point<R> &p2) { // 浮点数计算斜率（注意竖直为 inf）
  return (p1.y() - p2.y()) / (p1.x() - p2.x());
}

template< typename R >
R slope(const line<R> &l) {
  return slope(l.a, l.b);
}



