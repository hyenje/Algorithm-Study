//
// Created by 신현재 on 25. 7. 23.
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

vector<vector<ll> > arr(512, vector<ll>(512, -2));
vector<vector<ll> > v(512, vector<ll>(512, INF));

void solve() {
    int n, m, x = 0, y = 0;
    cin >> n >> m;

    vector<string> s(m);

    for (auto &i: s)
        cin >> i;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char k = s[i - 1][j - 1];
            if (k >= '0' && k <= '9') {
                arr[i][j] = k - '0';
            } else if (k == 'R')
                arr[i][j] = INF;
            else if (k == 'E')
                arr[i][j] = -1;
            else if (k == 'T')
                x = i, y = j, arr[i][j] = v[i][j] = 0;
        }
    }

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int> >, greater<> > pq;
    pq.emplace(0, x, y);
    ll answer = INF;
    while (!pq.empty()) {
        auto [cur, x, y] = pq.top();
        pq.pop();
        if (v[x][y] < cur) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x, ny = y;
            ll val = 0;

            while (true) {
                nx += mx[i], ny += my[i];
                if (arr[nx][ny] == INF) {
                    nx -= mx[i];
                    ny -= my[i];
                    break;
                }
                if (arr[nx][ny] == -1) {
                    answer = min(answer, cur + val);
                    break;
                }
                if (arr[nx][ny] == -2) break;
                val += arr[nx][ny];
            }

            if (arr[nx][ny] >= 0 && v[nx][ny] > cur + val) {
                v[nx][ny] = cur + val;
                pq.emplace(v[nx][ny], nx, ny);
            }
        }
    }

    if (answer == INF)
        cout << -1 << endl;
    else
        cout << answer << endl;
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
