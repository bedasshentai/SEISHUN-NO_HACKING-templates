// 依赖: point (type, 4.4.3), line (class, 4.4.2), segment (class, 4.4.5), perpendicular (function, 4.13.4)
template< typename R >
line<R> perpendicular_bisector(const segment<R> &s) { // 线段中垂线
  point<R> mid = (s.a + s.b) * 0.5;
  return line<R>(mid, mid + perpendicular<R>(s.b - s.a));
}



