// 依赖: point (type, 4.4.3), polygon (type, 4.4.4), cross_product (function, 4.13.2), sign (function, 4.16.8)
template< typename R >
polygon<R> minkowski_sum(const polygon<R> &p1, const polygon<R> &p2) { // 两凸多边形闵可夫斯基和
  int n = p1.size(), m = p2.size();
  polygon<R> v1(n), v2(m);
  for (int i = 0; i < n; i++) v1[i] = p1[(i + 1) % n] - p1[i];
  for (int i = 0; i < m; i++) v2[i] = p2[(i + 1) % m] - p2[i];

  polygon<R> ans = {p1[0] + p2[0]};
  int i = 0, j = 0;
  while (i < n && j < m) {
    point<R> v = sign(cross_product(v1[i], v2[j])) > 0 ? v1[i++] : v2[j++];
    ans.push_back(ans.back() + v);
  }
  while (i < n) ans.push_back(ans.back() + v1[i++]);
  while (j < m) ans.push_back(ans.back() + v2[j++]);
  return ans;
}



