// 依赖: point (type, 4.4.3), line (class, 4.4.2)
// 参数: A、B、C 为 Ax+By=C 系数
// 返回: 直线上两点
template< typename R >
line<R> general_to_two_point(R A, R B, R C) { // 一般式 Ax + By = C 转两点式
  R x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  if (A && B) {
    if (C) { x1 = 0, y1 = C / B; y2 = 0, x2 = C / A; }
    else { x1 = 1, y1 = -A / B; x2 = 0, y2 = 0; }
  } else if (A && !B) {
    if (C) { y1 = 0, x1 = C / A; y2 = 1, x2 = x1; }
    else { x1 = 0, y1 = 1; x2 = 0, y2 = 0; }
  } else if (!A && B) {
    if (C) { x1 = 0, y1 = C / B; x2 = 1, y2 = y1; }
    else { x1 = 1, y1 = 0; x2 = 0, y2 = 0; }
  } else {
    assert(false); // A == 0 && B == 0，不合法
  }
  return line<R>(point<R>(x1, y1), point<R>(x2, y2));
}




