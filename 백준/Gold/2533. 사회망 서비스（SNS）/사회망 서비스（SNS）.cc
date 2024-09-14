/*
 */
#include <bits/stdc++.h>
using namespace std;
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

vector<vector<int>> arr(1'000'123);
ll dp[1'000'123][2];
bool visited[1'000'123];

void go(int nd)
{
    ll val = 0;
    visited[nd] = 1;
    dp[nd][1]++;
    for (auto i : arr[nd])
    {
        if (visited[i])
            continue;
        go(i);
        dp[nd][0] += dp[i][1];
        dp[nd][1] += min(dp[i][0], dp[i][1]);
        // cout << i << '\n';
    }
    // cout << nd << '\n';
}

void solve()
{
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    go(1);

    // for (int i = 1; i <= n; i++)
    //     cout << dp[i][0] << ' ' << dp[i][1] << '\n';

    cout << min(dp[1][0], dp[1][1]);
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