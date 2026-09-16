#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, idx, p[N];
struct Node {
    int l, r, v, dist;
}tr[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool cmp(int x, int y) {
    if (tr[x].v != tr[y].v) return tr[x].v > tr[y].v;
    return x > y;
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (cmp(x, y)) swap(x, y);
    tr[x].r = merge(tr[x].r, y);
    if (tr[tr[x].l].dist < tr[tr[x].r].dist) swap(tr[x].l, tr[x].r);
    p[x] = p[y] = x;
    tr[x].dist = tr[tr[x].r].dist + 1;
    return x;
}

int main() {
    cin >> n;
    tr[0].v = 2e9;
    for (int i = 1; i <= n; i ++ ) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            tr[ ++ idx].v = x;
            p[idx] = idx;
        } else if (op == 2) {
            cin >> y;
            x = find(x), y = find(y);
            if (x != y) p[x] = p[y] = merge(x, y);
        } else if (op == 3) {
            cout << tr[find(x)].v << "\n";
        } else {
            x = find(x);
            p[tr[x].l] = p[tr[x].r] = p[x] = merge(tr[x].l, tr[x].r);
        }
    }
    return 0;
}