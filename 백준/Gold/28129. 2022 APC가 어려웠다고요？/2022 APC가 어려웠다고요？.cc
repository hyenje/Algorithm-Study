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
#define MOD 1'000'000'007
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll dp[3123][3123];
vector<pii> arr(3123);

void solve()
{
    int n, k;
    ll answer = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].F >> arr[i].S;
    for (int i = arr[1].F; i <= arr[1].S; i++)
    {
        dp[1][i] = 1;
        dp[2][max(1, i - k)] += dp[1][i];
        dp[2][min(3001, i + k + 1)] -= dp[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 3000; j++)
        {
            if (dp[i][j] + dp[i][j - 1] < 0)
                dp[i][j] += (ll)MOD;
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % (ll)MOD;
            if (arr[i].F <= j && arr[i].S >= j)
            {
                dp[i + 1][max(1, j - k)] = (dp[i + 1][max(1, j - k)] + dp[i][j]) % (ll)MOD;
                dp[i + 1][min(3001, j + k + 1)] = (dp[i + 1][min(3001, j + k + 1)] - dp[i][j]) % (ll)MOD;
            }
        }
    }
    for (int i = 1; i <= 3000; i++)
    {
        if (i >= arr[n].F && i <= arr[n].S)
            answer = (answer + dp[n][i]) % MOD;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= 10; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << answer << '\n';
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