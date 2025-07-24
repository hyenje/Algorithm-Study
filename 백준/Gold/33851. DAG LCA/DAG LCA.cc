//
// Created by 신현재 on 25. 7. 24.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define xll __int128
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define LL_INF 9'223'372'036'854'775'807
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 998'244'353
#define MID 200'000
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<int> > dist(2123, vector<int>(2123, INF));

void solve() {
    int a, b, n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > g(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        vector<int> visited(2123);
        queue<pii > que;
        que.push({i, 0});

        while (!que.empty()) {
            int x = que.front().first, val = que.front().second;
            que.pop();
            if (visited[x])
                continue;
            visited[x] = 1, dist[i][x] = val;

            for (auto i: g[x])
                que.push({i, val + 1});
        }
    }

    while (q--) {
        cin >> a >> b;
        int answer = INF;
        for (int i = 1; i <= n; i++) {
            if (dist[i][a] == INF || dist[i][b] == INF)
                continue;
            answer = min(answer, max(dist[i][a], dist[i][b]));
        }
        // cout << a_dist << ' ' << b_dist << ' ';
        cout << (answer == INF ? -1 : answer) << '\n';
    }
}

/*
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}

/*

*/
