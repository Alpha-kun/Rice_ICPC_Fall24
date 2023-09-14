#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ang(n);
    int gcd = 360;
    for (int i = 0; i < n; ++i) {
        cin >> ang[i];
        gcd = __gcd(gcd, ang[i]);
    }
    int q;
    for (int i = 0; i < k; ++i) {
        cin >> q;
        if (q % gcd == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
