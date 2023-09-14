#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<string>> sl(n, vector<string>(m));
    vector<set<string>> vs(n, set<string>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> sl[i][j];
            vs[i].insert(sl[i][j]);
        }
    }

    vector<string> ans;
    for (int j = 0; j < m; ++j) {
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (vs[i].find(sl[0][j]) == vs[i].end()) flag = false;
        }
        if (flag) ans.push_back(sl[0][j]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (string s: ans) {
        cout << s << endl;
    }
    return 0;
}
