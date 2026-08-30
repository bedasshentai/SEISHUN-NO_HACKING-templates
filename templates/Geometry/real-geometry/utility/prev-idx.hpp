// 依赖: usize (type, 4.5.5)
inline usize prev_idx(usize idx, usize size) {
  return idx ? idx - 1 : size - 1;
}



