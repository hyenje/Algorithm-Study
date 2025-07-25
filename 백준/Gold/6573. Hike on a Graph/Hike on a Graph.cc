//
// Created by 신현재 on 25. 7. 25.
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

int solve() {
    int n;
    cin >> n;
    if (n == 0) return 1;

    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<char> > arr(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];

    queue<tuple<int, int, int> > q;
    map<tuple<int, int, int>, int> dist;

    vector<int> start = {a, b, c};
    sort(start.begin(), start.end());
    q.emplace(start[0], start[1], start[2]);
    dist[{start[0], start[1], start[2]}] = 0;

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        int d = dist[{x, y, z}];
        if (x == y && y == z) {
            cout << d << '\n';
            return 0;
        }

        for (int i = 1; i <= n; ++i) {
            // move z
            if (arr[x][y] == arr[z][i]) {
                vector<int> nxt = {x, y, i};
                sort(nxt.begin(), nxt.end());
                tuple<int, int, int> state = {nxt[0], nxt[1], nxt[2]};
                if (!dist.count(state)) {
                    dist[state] = d + 1;
                    q.push(state);
                }
            }
            // move y
            if (arr[x][z] == arr[y][i]) {
                vector<int> nxt = {x, i, z};
                sort(nxt.begin(), nxt.end());
                tuple<int, int, int> state = {nxt[0], nxt[1], nxt[2]};
                if (!dist.count(state)) {
                    dist[state] = d + 1;
                    q.push(state);
                }
            }
            // move x
            if (arr[y][z] == arr[x][i]) {
                vector<int> nxt = {i, y, z};
                sort(nxt.begin(), nxt.end());
                tuple<int, int, int> state = {nxt[0], nxt[1], nxt[2]};
                if (!dist.count(state)) {
                    dist[state] = d + 1;
                    q.push(state);
                }
            }
        }
    }

    cout << "impossible\n";
    return 0;
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
    while (true) {
        if (solve())
            break;
    }

    return 0;
}

/*

*/
