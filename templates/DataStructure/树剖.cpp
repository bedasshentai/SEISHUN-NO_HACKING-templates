#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, m;
int w[N], h[N], e[N << 1], ne[N << 1], idx;
int id[N], nw[N], cnt;
int dep[N], sz[N], top[N], fa[N], son[N];
struct Node {
    int l, r;
    ll add, sum;
}tr[N << 2];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs1(int u, int f, int d) {
    dep[u] = d, sz[u] = 1, fa[u] = f;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == f) continue;
        dfs1(j, u, d + 1);
        sz[u] += sz[j];
        if (sz[son[u]] < sz[j]) son[u] = j;
    }
}

void dfs2(int u, int t) {
    id[u] = ++ cnt, top[u] = t, nw[cnt] = w[u];
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa[u] || j == son[u]) continue;
        dfs2(j, j);
    }
}

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    if (tr[u].add) {
        tr[u << 1].sum += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].add;
        tr[u << 1].add += tr[u].add;
        tr[u << 1 | 1].sum += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].add;
        tr[u << 1 | 1].add += tr[u].add;
        tr[u].add = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].sum = nw[r];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, ll d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

ll query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

void modify_path(int u, int v, ll d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        modify(1, id[top[u]], id[u], d);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    modify(1, id[u], id[v], d);
}

ll query_path(int u, int v) {
    ll res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res += query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    res += query(1, id[u], id[v]);
    return res;
}

void modify_tree(int u, int k) {
    modify(1, id[u], id[u] + sz[u] - 1, k);
}

ll query_tree(int u) {
    return query(1, id[u], id[u] + sz[u] - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs1(1, 0, 0);
    dfs2(1, 1);
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i ++ ) {
        int op, u, v, k;
        cin >> op >> u;
        if (op == 1) {
            cin >> v >> k;
            modify_path(u, v, k);
        }
        else if (op == 2) {
            cin >> k;
            modify_tree(u, k);
        }
        else if (op == 3) {
            cin >> v;
            cout << query_path(u, v) << "\n";
        }
        else cout << query_tree(u) << "\n";
    }
    return 0;
}