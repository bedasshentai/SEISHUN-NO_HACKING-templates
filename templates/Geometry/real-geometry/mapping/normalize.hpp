// 依赖: point (type, 4.4.3)
template< typename R >
point<R> normalize(const point<R> &v) { // 单位向量
  return v / std::abs(v);
}



