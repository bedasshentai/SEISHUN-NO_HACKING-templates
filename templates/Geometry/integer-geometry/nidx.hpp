// 依赖: usize (type, 5.1)
inline usize nidx(usize idx, usize size) {
  return idx + 1 == size ? 0 : idx + 1;
}



