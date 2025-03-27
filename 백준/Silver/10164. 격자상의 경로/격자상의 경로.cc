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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll arr[20][20];

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll x = k / m + 1, y = k % m;
    // cout << x << ' ' << y << '\n';
    for (int i = 1; i <= n; i++)
        arr[i][1] = 1;
    for (int j = 1; j <= m; j++)
        arr[1][j] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];

    if (k == 0)
        cout << arr[n][m] << '\n';
    else
        // cout << arr[x][y] << ' ' << arr[n - x + 1][m - y + 1] << '\n';
        cout << arr[x][y] * arr[n - x + 1][m - y + 1] << '\n';
}
int main()
{
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