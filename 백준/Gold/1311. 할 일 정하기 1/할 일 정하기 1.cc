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

vector<vector<int>> dp(21, vector<int>(1 << 20, l_INF));
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        dp[0][1 << i] = arr[i][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < (1 << n); j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (j ^ (1 << k))
                    dp[i][j | (1 << k)] = min(dp[i - 1][j] + arr[k][i], dp[i][j | (1 << k)]);
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1] << '\n';
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