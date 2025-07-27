//
// Created by 신현재 on 25. 7. 27.
//
/*
*/
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

int visited[512][512][4];

int is_right(int a, int b) {
    if (a == 0 && b == 2)
        return 1;
    if (a == 1 && b == 3)
        return 1;
    if (a == 2 && b == 1)
        return 1;
    if (a == 3 && b == 0)
        return 1;
    return 0;
}

void solve() {
    int n, m, x = 0, y = 0, z = 0;
    cin >> n >> m;
    vector<vector<int> > arr(n + 2, vector<int>(m + 2, INF));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'S')
                x = i + 1, y = j + 1, arr[i + 1][j + 1] = 0;
            else if (s[j] == '.')
                arr[i + 1][j + 1] = 0;
            else if (s[j] == 'E')
                arr[i + 1][j + 1] = 1;
        }
    }

    queue<vector<int> > q;
    q.push({x, y, 0});
    q.push({x, y, 1});
    q.push({x, y, 2});
    q.push({x, y, 3});

    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        x = v[0], y = v[1], z = v[2];
        if (arr[x][y] == 1) {
            cout << visited[x][y][z] << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + mx[i], ny = y + my[i];
            if (visited[nx][ny][i] || arr[nx][ny] == INF || is_right(z, i))
                continue;
            visited[nx][ny][i] = visited[x][y][z] + 1;
            q.push({nx, ny, i});
        }
    }

    cout << -1 << endl;
}

/*
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    solve();

    return 0;
}

/*

*/
