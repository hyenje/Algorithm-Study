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

void solve()
{
    int n, answer = 0;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (auto &i : arr)
    {
        cin >> i;
        answer = max(i, answer);
    }

    for (int i = 0; i < n; i++)
        dp[i][i] = arr[i];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (dp[j][j + k] && dp[j + k + 1][j + i] && dp[j][j + k] == dp[j + k + 1][j + i])
                    dp[j][j + i] = dp[j][j + k] + 1;
            }
            answer = max(answer, dp[j][j + i]);
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