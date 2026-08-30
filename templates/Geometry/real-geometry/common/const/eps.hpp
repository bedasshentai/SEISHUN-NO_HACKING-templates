// 依赖: f80 (type, 4.5.3)
inline static f80 &eps() {
  static f80 EPS = 1e-10;
  return EPS;
}

// 依赖: f80 (type, 4.5.3)
void set_eps(f80 EPS) {
  eps() = EPS;
}



