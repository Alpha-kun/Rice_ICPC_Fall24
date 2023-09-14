#include <bits/stdc++.h>

using namespace std;

typedef bitset<5000> bs;

vector<int> G[5000], Gr[5000];
bs dp1[5000] = {0}, dp2[5000] = {0};
bool mark1[5000] = {false}, mark2[5000] = {false};

void dfs(int u) {
    mark1[u] = true;
    dp1[u][u] = true;
    if (G[u].size() == 0) return;
    for (int v: G[u]) {
        if (!mark1[v]) dfs(v);
        dp1[u] |= dp1[v];
    }
}

void dfsr(int u) {
    mark2[u] = true;
    dp2[u][u] = true;
    if (Gr[u].size() == 0) return;
    for (int v: Gr[u]) {
        if (!mark2[v]) dfsr(v);
        dp2[u] |= dp2[v];
    }
}

int main() {
    int a, b, n, m, u, v;
    cin >> a >> b >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        Gr[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!mark1[i]) dfs(i);
        if (!mark2[i]) dfsr(i);
    }

    int cnt[n], cntr[n];
    for (int i = 0; i < n; ++i) {
        cnt[i] = dp1[i].count();
        cntr[i] = dp2[i].count();
    }

    int ansa = 0, ansb = 0, ansc = 0;
    for (int i = 0; i < n; ++i) {
        if (a > n - cnt[i]) ansa++;
        if (b > n - cnt[i]) ansb++;
        if (b < cntr[i]) ansc++;
    }

    cout << ansa << endl;
    cout << ansb << endl;
    cout << ansc << endl;
    return 0;
}
