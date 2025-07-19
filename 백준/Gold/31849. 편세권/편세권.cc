//
// Created by 신현재 on 25. 7. 10.
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

vector<vector<ll> > num(1123, vector<ll>(1123));

void solve() {
    ll n, m, r, c;
    ll x, y, z;

    cin >> n >> m >> r >> c;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            num[i][j] = INF;
        }
    }

    vector<vector<ll> > arr;
    for (ll i = 1; i <= r; i++) {
        cin >> x >> y >> z;
        arr.push_back({x, y, z});
    }
    queue<pii > q;
    for (ll i = 1; i <= c; i++) {
        cin >> x >> y;
        num[x][y] = 0;
        q.push({x, y});
    }

    while (q.size()) {
        x = q.front().F, y = q.front().S;
        q.pop();

        for (ll i = 0; i < 4; i++) {
            ll nx = x + mx[i], ny = y + my[i];
            if (num[nx][ny] != INF)
                continue;
            num[nx][ny] = num[x][y] + 1;
            q.push({nx, ny});
        }
    }
    ll answer = INFINITY;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++)
    //         cout << num[i][j] << " ";
    //     cout << endl;
    // }
    for (auto i: arr)
        answer = min(answer, num[i[0]][i[1]] * i[2]);

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
