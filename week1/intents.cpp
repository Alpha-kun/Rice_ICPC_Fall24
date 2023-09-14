#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct point {
    int x, y;

    bool operator<(point p) const {
        return atan2(y, x) < atan2(p.y, p.x);
    }
};

ll area(point p, point q) {
    return p.x * q.y - q.x * p.y;
}

int main() {
    int n;
    cin >> n;

    vector<point> pts;
    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        pts.push_back({x, y});
    }
    sort(pts.begin(), pts.end());

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());

    ll sA = 0;
    vector<ll> A(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        A[i] = area(pts[i], pts[(i + 1) % (n - 1)]);
        sA += A[i];
    }

    vector<ll> c(n);
    for (int i = 0; i < n - 1; ++i) {
        c[i] = A[i] + A[(i + 1) % (n - 1)];
    }
    c[n - 1] = sA;
    sort(c.begin(), c.end());

    ll ans = 0ll;
    for (int i = 0; i < n; ++i) {
        ans += c[i] * h[i];
    }

    printf("%.8f\n", ans / 6.0);
    return 0;
}