// 依赖: lattice_point (class, 5.9), det (function, 5.4), dot (function, 5.5)
// 参数: 动态凸包：add(p) 插点、contains(p) 判点在包内、empty() 判空
template< typename Z >
struct dynamic_convex_hull { // 动态凸包：支持插入点与判定点是否在凸包内
  using pt = lattice_point< Z >;

  struct Edge {
    static int cmp;
    mutable pt a, b;
    bool operator<(const Edge &o) const { return cmp ? a < o.a : turn_right(b, o.b); }
  };

  static bool turn_right(const pt &a, const pt &b) {
    return det(a, b) < 0 || (det(a, b) == 0 && dot(a, b) < 0);
  }

  struct upper_hull : std::set< Edge > {
    bool contains(const pt &p) const {
      auto it = this->lower_bound(Edge{p, pt()});
      if (it != this->end() && it->a == p) return true;
      if (it != this->begin() && it != this->end() && det(std::prev(it)->b, p - std::prev(it)->a) <= 0) return true;
      return false;
    }

    void add(const pt &p) {
      if (contains(p)) return;
      auto it = this->lower_bound(Edge{p, pt()});
      for (; it != this->end(); it = this->erase(it)) {
        if (turn_right(it->a - p, it->b)) break;
      }
      for (; it != this->begin() && std::prev(it) != this->begin(); this->erase(std::prev(it))) {
        if (turn_right(std::prev(std::prev(it))->b, p - std::prev(std::prev(it))->a)) break;
      }
      if (it != this->begin()) std::prev(it)->b = p - std::prev(it)->a;
      if (it == this->end()) this->insert(Edge{p, pt(0, -1)});
      else this->insert(Edge{p, it->a - p});
    }
  };

  upper_hull up, low;

  bool empty() const { return up.empty(); }

  bool contains(const pt &p) const {
    Edge::cmp = 1;
    return up.contains(p) && low.contains(pt(-p.x(), -p.y()));
  }

  void add(const pt &p) {
    Edge::cmp = 1;
    up.add(p);
    low.add(pt(-p.x(), -p.y()));
  }
};

template< typename Z >
int dynamic_convex_hull< Z >::Edge::cmp = 1;




