#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD 1000000007
int n;
string s;
ll dp[201][200][200];
ll p26[201];

ll f(int i, int j, int k) {
    if ((k - j + 1) > 2 * i) return 0;
    if (j > k) return p26[i];
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (s[j] != s[k]) {
        dp[i][j][k] = 24 * f(i - 1, j, k);
        dp[i][j][k] += f(i - 1, j + 1, k) + f(i - 1, j, k - 1);
        dp[i][j][k] %= MOD;
    } else {
        dp[i][j][k] = 25 * f(i - 1, j, k);
        dp[i][j][k] += f(i - 1, j + 1, k - 1);
        dp[i][j][k] %= MOD;
    }
    return dp[i][j][k];
}

int main() {
    p26[0] = 1;
    for (int i = 1; i <= 200; ++i) {
        p26[i] = (p26[i - 1] * 26) % MOD;
    }
    memset(dp, -1l, sizeof(dp));
    cin >> n >> s;
    cout << f(n, 0, n - 1);
    return 0;
}