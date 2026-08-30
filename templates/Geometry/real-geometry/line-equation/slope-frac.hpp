// 依赖: point (type, 4.4.3), fraction (class, 4.12.2)
// 参数: p1、p2 为两个整数点
// 返回: 精确分数斜率
template< typename Z >
fraction< Z > slope_frac(const point< Z > &p1, const point< Z > &p2) { // 分数精确计算斜率
  return fraction< Z >(p1.y() - p2.y(), p1.x() - p2.x());
}




