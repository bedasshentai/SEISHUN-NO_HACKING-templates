// 依赖: 
template< typename R >
struct point3d {
  R x, y, z;
  point3d(R x_ = 0, R y_ = 0, R z_ = 0) : x(x_), y(y_), z(z_) {}

  point3d &operator+=(const point3d &p) { x += p.x; y += p.y; z += p.z; return *this; }
  point3d &operator-=(const point3d &p) { x -= p.x; y -= p.y; z -= p.z; return *this; }
  point3d &operator*=(R t) { x *= t; y *= t; z *= t; return *this; }
  point3d &operator/=(R t) { x /= t; y /= t; z /= t; return *this; }

  friend point3d operator+(point3d a, const point3d &b) { return a += b; }
  friend point3d operator-(point3d a, const point3d &b) { return a -= b; }
  friend point3d operator*(point3d a, R t) { return a *= t; }
  friend point3d operator*(R t, point3d a) { return a *= t; }
  friend point3d operator/(point3d a, R t) { return a /= t; }
  friend bool operator==(const point3d &a, const point3d &b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
  friend bool operator!=(const point3d &a, const point3d &b) { return !(a == b); }

  friend std::istream &operator>>(std::istream &is, point3d &p) { return is >> p.x >> p.y >> p.z; }
  friend std::ostream &operator<<(std::ostream &os, const point3d &p) {
    return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
  }
};

template< typename R >
using vec3d = point3d< R >;



