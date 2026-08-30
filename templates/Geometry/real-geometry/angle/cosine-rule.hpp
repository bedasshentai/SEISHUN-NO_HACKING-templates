// 依赖: 
// 参数: a、b、c 为三边长，c 为所求角的对边
// 返回: 该角弧度
template< typename R >
R cosine_rule(R a, R b, R c) { // 余弦定理：已知三边，求 c 边对角（弧度）
  return std::acos((a * a + b * b - c * c) / (2 * a * b));
}




