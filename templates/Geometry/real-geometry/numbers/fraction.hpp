// 依赖: 
template< typename Z >
struct fraction { // 精确分数，den >= 0；den == 0 表示无穷（num 为符号）
  Z num, den;

  fraction(Z n = 0, Z d = 1) : num(n), den(d) { normalize(); }

  void normalize() {
    if (den < 0) { num = -num; den = -den; }
    Z g = std::gcd(std::abs(num), std::abs(den));
    num /= g;
    den /= g;
  }

  friend fraction operator-(fraction a) { return fraction(-a.num, a.den); }
  friend fraction operator-(fraction a, const fraction &b) {
    return fraction(a.num * b.den - b.num * a.den, a.den * b.den);
  }
  friend fraction operator/(const fraction &a, const fraction &b) {
    return fraction(a.num * b.den, a.den * b.num);
  }
  friend std::ostream &operator<<(std::ostream &os, const fraction &f) {
    return os << f.num << '/' << f.den;
  }
};



