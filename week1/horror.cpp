#include <bits/stdc++.h>

using namespace std;

vector<int> G[1000];

int main() {
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> hrr(h);
    for (int i = 0; i < h; ++i) {
        cin >> hrr[i];
    }
    int a, b;
    for (int i = 0; i < l; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> vis(1000, false);
    vector<int> dist(1000, INT32_MAX);
    list<int> q;
    for (int mv: hrr) {
        vis[mv] = true;
        dist[mv] = 0;
        q.push_back(mv);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (!vis[v]) {
                vis[v] = true;
                q.push_back(v);
                dist[v] = dist[u] + 1;
            }
        }
    }

    int maxi = -1;
    for (int i = 0; i < n; ++i) {
        maxi = max(maxi, dist[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i] == maxi) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
