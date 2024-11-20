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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll arr[500][500];

ll prefix(int i, int j, int a, int b)
{
    return arr[i][j] - arr[i - a][j] - arr[i][j - b] + arr[i - a][j - b];
}
void solve()
{
    ll n, m, a, b, c, answer = INF;
    cin >> n >> m >> a >> b >> c;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (i >= a && j >= b + c)
                answer = min(answer, prefix(i, j, a, b + c));
            if (i >= a + b && j >= a + c)
                answer = min(answer, prefix(i, j, b, a) + prefix(i - b, j - a, a, c));
            if (i >= a + c && j >= a + b)
                answer = min(answer, prefix(i, j, c, a) + prefix(i - c, j - a, a, b));
        }
    }

    cout << answer << '\n';
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