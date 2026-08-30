// 依赖: pi (function, 4.5.2)
// 参数: l 为棱长，n 为棱数
// 返回: 正 n 棱锥体积
template< typename R >
R pyramid_volume(R l, int n) { // 正 n 棱锥体积（棱长为 l）
  R p = static_cast< R >(pi());
  return l * l * l * n / (12 * std::tan(p / n)) * std::sqrt(1 - 1 / (4 * std::sin(p / n) * std::sin(p / n)));
}




