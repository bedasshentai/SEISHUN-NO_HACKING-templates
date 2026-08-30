// 依赖: f80 (type, 4.5.3)
static f80 pi() {
  static const f80 PI = acosl(-1); // no need `std::`. (?)
  return PI;
}



