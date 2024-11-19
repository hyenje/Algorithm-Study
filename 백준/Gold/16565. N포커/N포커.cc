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
#define MOD 10'007
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll dp[128][128];

void solve()
{
    int n, val = 52, answer = 0;
    cin >> n;

    for (int i = 4; i <= n; i += 4)
    {
        if ((i >> 2) % 2 == 1)
            answer = (answer + dp[52 - i][n - i] * dp[13][i >> 2]) % MOD;
        else
            answer = (answer - (dp[52 - i][n - i] * dp[13][i >> 2]) % MOD + MOD) % MOD;
    }

    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    dp[0][0] = 1;
    for (int i = 1; i < 100; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= 100; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    }

    // for (int i = 0; i <= 52; i++)
    // {
    //     for (int j = 0; j <= 26; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */