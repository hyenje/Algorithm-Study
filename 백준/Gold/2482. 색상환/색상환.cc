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
#define MOD 1'000'000'003
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll dp[1024][1024];

void solve()
{
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i <= n; i++)
        dp[i][1] = i;

    for (ll i = 2; i <= n; i++)
    {
        if ((i << 1) <= n)
            dp[i << 1][i] = 2;

        for (ll j = (i << 1) + 1; j <= n; j++)
            dp[j][i] = (dp[j - 1][i] + dp[j - 2][i - 1]) % (ll)MOD;
    }

    cout << dp[n][m] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */