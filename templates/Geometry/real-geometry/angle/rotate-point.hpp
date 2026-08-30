// 依赖: point (type, 4.4.3)
// 参数: p 为待旋转点，o 为旋转中心，rad 为弧度
// 返回: 旋转后的点
template< typename R >
point<R> rotate_point(const point<R> &p, const point<R> &o, R rad) { // 点绕点旋转任意角度
  R x = (p.x() - o.x()) * std::cos(rad) + (p.y() - o.y()) * std::sin(rad) + o.x();
  R y = (o.x() - p.x()) * std::sin(rad) + (p.y() - o.y()) * std::cos(rad) + o.y();
  return point<R>(x, y);
}




