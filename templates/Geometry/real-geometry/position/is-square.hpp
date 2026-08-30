// 依赖: point (type, 4.4.3), line (class, 4.4.2), compare_x (function, 4.6.1), distance_pp (function, 4.9.4), is_parallel (function, 4.15.5), is_orthogonal (function, 4.15.4), equals (function, 4.16.1), sign (function, 4.16.8)
// 参数: p 为包含 4 个点的点集
// 返回: 非布尔：0 不能 / 1 矩形 / 2 正方形
template< typename R >
int is_square(points<R> p) { // 判断四点能否组成矩形/正方形：0 否, 1 矩形, 2 正方形
  std::sort(p.begin(), p.end(), compare_x<R>);
  if (equals(distance_pp(p[0], p[1]), distance_pp(p[2], p[3])) && sign(distance_pp(p[0], p[1])) &&
      equals(distance_pp(p[0], p[2]), distance_pp(p[1], p[3])) && sign(distance_pp(p[0], p[2])) &&
      is_parallel(line<R>(p[0], p[1]), line<R>(p[2], p[3])) &&
      is_parallel(line<R>(p[0], p[2]), line<R>(p[1], p[3])) &&
      is_orthogonal(line<R>(p[0], p[1]), line<R>(p[0], p[2]))) {
    return equals(distance_pp(p[0], p[1]), distance_pp(p[0], p[2])) ? 2 : 1;
  }
  return 0;
}





