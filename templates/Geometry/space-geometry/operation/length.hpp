// 依赖: point3d (class, 6.2.3)
template< typename R >
R length3d(const point3d< R > &v) { // 原点到当前点的距离
  return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template< typename R >
R distance3d(const point3d< R > &a, const point3d< R > &b) { // 三维欧几里得距离
  return length3d(a - b);
}

template< typename R >
point3d< R > normalize3d(const point3d< R > &v) { // 三维单位向量
  return v / length3d(v);
}



