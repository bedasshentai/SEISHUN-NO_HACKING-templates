#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e9;

int n, idx;
ll ans, R;
struct Point {
    ll x, y;
}a[N];
struct Node {
    int ls, rs, sz;
    ll x, y;
    ll X[2], Y[2];
}tr[N];

ld sqr(ld x) {
    return x * x;
}

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void pushup(int u) {
    tr[u].sz = 1;
    tr[u].X[0] = tr[u].X[1] = tr[u].x;
    tr[u].Y[0] = tr[u].Y[1] = tr[u].y;
    int ls = tr[u].ls, rs = tr[u].rs;
    if (ls) {
        tr[u].sz += tr[ls].sz;
        tr[u].X[0] = min(tr[u].X[0], tr[ls].X[0]);
        tr[u].X[1] = max(tr[u].X[1], tr[ls].X[1]);
        tr[u].Y[0] = min(tr[u].Y[0], tr[ls].Y[0]);
        tr[u].Y[1] = max(tr[u].Y[1], tr[ls].Y[1]);
    }
    if (rs) {
        tr[u].sz += tr[rs].sz;
        tr[u].X[0] = min(tr[u].X[0], tr[rs].X[0]);
        tr[u].X[1] = max(tr[u].X[1], tr[rs].X[1]);
        tr[u].Y[0] = min(tr[u].Y[0], tr[rs].Y[0]);
        tr[u].Y[1] = max(tr[u].Y[1], tr[rs].Y[1]);
    }
}

int build(int l, int r) {
    if (l > r) return 0;
    ld ave_x = 0, ave_y = 0;      // x, y上，按方差大的进行划分
    for (int i = l; i <= r; i ++ ) {
        ave_x += a[i].x;
        ave_y += a[i].y;
    }
    ave_x /= r - l + 1;
    ave_y /= r - l + 1;
    ld var_x = 0, var_y = 0;
    for (int i = l; i <= r; i ++ ) {
        var_x += sqr(a[i].x - ave_x);
        var_y += sqr(a[i].y - ave_y);
    }
    int mid = l + r >> 1;
    if (var_x > var_y) {
        nth_element(a + l, a + mid, a + r + 1,
        [](const Point &x, const Point &y){
            return x.x < y.x;
        });
    } else {
        nth_element(a + l, a + mid, a + r + 1,
        [](const Point &x, const Point &y){
            return x.y < y.y;
        });
    }
    int u = ++ idx;
    tr[u].x = a[mid].x;
    tr[u].y = a[mid].y;
    tr[u].ls = build(l, mid - 1);
    tr[u].rs = build(mid + 1, r);
    pushup(u);
    return u;
}

ll min_dist(int u, ll x, ll y) {
    if (!u) return 2e18;
    ll dx = max(0LL, max(tr[u].X[0] - x, x - tr[u].X[1]));
    ll dy = max(0LL, max(tr[u].Y[0] - y, y - tr[u].Y[1]));
    return dx * dx + dy * dy;
}

ll max_dist(int u, ll x, ll y) {
    if (!u) return 0;
    ll dx = max(abs(x - tr[u].X[0]), abs(x - tr[u].X[1]));
    ll dy = max(abs(y - tr[u].Y[0]), abs(y - tr[u].Y[1]));
    return dx * dx + dy * dy;
}

void query(int u, ll x, ll y, ll R) {
    if (!u) return;
    if (min_dist(u, x, y) > R) return;
    if (max_dist(u, x, y) <= R) return ans += tr[u].sz, void();
    ll d = dist(x, y, tr[u].x, tr[u].y);
    if (d <= R) ans ++ ;
    query(tr[u].ls, x, y, R);
    query(tr[u].rs, x, y, R);
}

void solve() {
    cin >> n >> R;
    for (int i = 1; i <= n; i ++ ) cin >> a[i].x >> a[i].y;
    build(1, n);
    for (int i = 1; i <= n; i ++ ) query(1, a[i].x, a[i].y, R * R);
    cout << (ans - n) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T -- ) solve();
    return 0;
}