// n cases of x equiv mi (mod ai)
int main() {
    int n;
    cin >> n;
    bool has_answer = true;
    ll a1, m1;
    cin >> a1 >> m1;
    for (int i = 0; i < n - 1; i ++ ) {
        ll a2, m2;
        cin >> a2 >> m2;
        ll k1, k2;
        ll d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) {
            has_answer = false;
            break;
        }
        k1 *= (m2 - m1) / d;
        ll t = a2 / d;
        k1 = (k1 % t + t) % t;
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if (has_answer) cout << (m1 % a1 + a1) % a1 << "\n";
    else cout << "-1\n";
    return 0;
}