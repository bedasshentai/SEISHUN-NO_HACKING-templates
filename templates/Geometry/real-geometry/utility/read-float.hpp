// 依赖: 
// 参数: k 为保留的小数位数
// 返回: 原数放大 10^k 倍的整数
inline int read_float(int k = 4) { // 字符串读入浮点数，返回放大 10^k 倍后的整数
  std::string s;
  std::cin >> s;

  int num = 0;
  auto it = s.find('.');
  if (it != std::string::npos) {
    num = static_cast< int >(s.size() - it - 1);
    s.erase(s.begin() + it);
  }
  for (int i = 1; i <= k - num; i++) s += '0';
  return std::stoi(s);
}




