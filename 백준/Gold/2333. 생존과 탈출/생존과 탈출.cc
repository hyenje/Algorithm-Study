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

vector<vector<pii>> arr(1024);
vector<vector<int>> dp(1024, vector<int>(100, -1));

int solve()
{
    int d, n, t, f, h;
    cin >> d >> n;
    dp[0][0] = 10;

    for (int i = 0; i < n; i++)
    {
        cin >> t >> f >> h;
        arr[t].push_back({f, h});
    }

    for (int i = 1; i < 1024; i++)
    {
        int flag = 0;
        for (auto k : arr[i])
        {
            vector<int> tmp = dp[i];
            for (int j = 0; j < d; j++)
            {
                if (dp[i - 1][j] > 0)
                {
                    flag = 1;
                    tmp[j] = max(tmp[j], dp[i - 1][j] + k.F - 1);
                    if (j + k.S >= d)
                    {
                        // cout << j + k.S << '\n';
                        return i;
                    }
                    else
                        tmp[j + k.S] = max(tmp[j + k.S], dp[i - 1][j] - 1);
                }
                if (dp[i][j] >= 0)
                {
                    tmp[j] = max(tmp[j], dp[i][j] + k.F);
                    if (j + k.S >= d)
                    {
                        // cout << j + k.S << '\n';
                        return i;
                    }
                    else
                        tmp[j + k.S] = max(tmp[j + k.S], dp[i][j]);
                }
            }
            dp[i] = tmp;
        }
        if (arr[i].empty())
        {
            for (int j = 0; j < d; j++)
            {
                if (dp[i - 1][j] > 0)
                {
                    flag = 1;
                    dp[i][j] = dp[i - 1][j] - 1;
                }
            }
        }
        if (!flag)
        {
            // cout << "2\n";
            return i - 1;
        }
    }

    int answer = 1000;
    for (auto i : dp[1000])
        answer = max(answer, 1000 + i);
    // cout << 3 << '\n';
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    cout << solve() << '\n';

    // for (auto i : dp[1000])
    //     cout << i << ' ';

    // for (int i = 0; i <= 65; i++)
    // {
    //     cout << i << ": :";
    //     for (int j = 0; j <= 50; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }

    return 0;
}
/*
 */